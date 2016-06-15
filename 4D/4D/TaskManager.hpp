#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <list>
#include <functional>

#include "GlobalMutex.hpp"



class TaskManager
{
private:
	unsigned int mNumberOfThreads;
	std::deque<std::function<void()>> mDequeOfTasks;
	std::list<std::thread*> mListOfThreads;

	std::function<void()> *pExecuteFunction;
	std::thread *pThreadOfExecution;
	std::function<void()> createExecuteFunction();

	std::mutex mMutexOfList;
	std::mutex mMutexOfDeque;
	std::mutex mMutexOfMemberVariables; //Defends mTasksRemain & mJoinCalled & mWasStarted & mNumberOfThreads

	bool mTasksRemain;
	bool mJoinCalled;
	bool mWasStarted;

public:
	TaskManager();
	TaskManager(unsigned int numberOfThreads);

	~TaskManager();

	void addTask(std::function<void()> task);
	void join();
	void start();


};





#endif