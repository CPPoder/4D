#include "TaskManager.hpp"

//Default Constructor
TaskManager::TaskManager()
	: TaskManager(2)
{
}

//Parameter Constructor
TaskManager::TaskManager(unsigned int numberOfThreads)
	: mNumberOfThreads(numberOfThreads),
	  mDequeOfTasks(),
	  mListOfThreads(),
	  mTasksRemain(false),
	  mJoinCalled(false),
	  mWasStarted(false)
{
	pExecuteFunction = new std::function<void()>(createExecuteFunction());
	pThreadOfExecution = nullptr;
}

//Destructor
TaskManager::~TaskManager()
{
	mMutexOfMemberVariables.lock();
	bool joinCalled = mJoinCalled;
	mMutexOfMemberVariables.unlock();

	if (!joinCalled)
	{
		join(); //Prevents from loosing threads due to Destructor call (In case of call: Waits until all threads are finished!)
	}

	mMutexOfMemberVariables.lock();
	if (mWasStarted)
	{
		delete pThreadOfExecution;
		pThreadOfExecution = nullptr;
	}
	mMutexOfMemberVariables.unlock();

	delete pExecuteFunction;
	pExecuteFunction = nullptr;
}

//Add Task
void TaskManager::addTask(std::function<void()> task)
{
	mMutexOfDeque.lock();
	mDequeOfTasks.push_back(task);
	mMutexOfDeque.unlock();
}

//Join
void TaskManager::join()
{
	start();

	mMutexOfMemberVariables.lock();
	mJoinCalled = true;
	mMutexOfMemberVariables.unlock();

	pThreadOfExecution->join();
}

//Start
void TaskManager::start()
{
	mMutexOfMemberVariables.lock();
	mWasStarted = true;
	mMutexOfMemberVariables.unlock();

	pThreadOfExecution = new std::thread(*pExecuteFunction);
}

//Create Execute Function
std::function<void()> TaskManager::createExecuteFunction()
{
	return [this](){
		mMutexOfMemberVariables.lock();
		bool tasksRemain = mTasksRemain;
		bool joinCalled = mJoinCalled;
		mMutexOfMemberVariables.unlock();

		while (tasksRemain || !joinCalled)
		{
			//Join the first Thread
			mMutexOfList.lock();
			if (!mListOfThreads.empty())
			{
				mListOfThreads.front()->join();
				delete mListOfThreads.front();
				mListOfThreads.pop_front();
			}
			mMutexOfList.unlock();

			//Fill up mListOfThreads if possible
			mMutexOfList.lock();
			mMutexOfDeque.lock();
			mMutexOfMemberVariables.lock();
			while ((mListOfThreads.size() < mNumberOfThreads) && (!mDequeOfTasks.empty()))
			{
				mListOfThreads.push_back(new std::thread(mDequeOfTasks.front()));
				mDequeOfTasks.pop_front();
			}
			mMutexOfList.unlock();
			mMutexOfDeque.unlock();
			mMutexOfMemberVariables.unlock();

			//Determine if tasks remain
			mMutexOfList.lock();
			mMutexOfDeque.lock();
			mTasksRemain = !(mListOfThreads.empty() && mDequeOfTasks.empty());
			mMutexOfList.unlock();
			mMutexOfDeque.unlock();

			//Refresh tasksRemain and joinCalled
			mMutexOfMemberVariables.lock();
			tasksRemain = mTasksRemain;
			joinCalled = mJoinCalled;
			mMutexOfMemberVariables.unlock();
		}
	};
}