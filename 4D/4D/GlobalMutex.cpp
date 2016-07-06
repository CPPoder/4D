#include "stdafx.h"
#include "GlobalMutex.hpp"

//Initialize static variables
//std::mutex initializer;
std::mutex GlobalMutex::mStreamMutex;
std::mutex GlobalMutex::mOtherMutex;


//Constructor
GlobalMutex::GlobalMutex()
{
}

//Destructor
GlobalMutex::~GlobalMutex()
{
}

//Locker
void GlobalMutex::lockStreamMutex()
{
	mStreamMutex.lock();
}
void GlobalMutex::lockOtherMutex()
{
	mOtherMutex.lock();
}

//Unlocker
void GlobalMutex::unlockStreamMutex()
{
	mStreamMutex.unlock();
}
void GlobalMutex::unlockOtherMutex()
{
	mOtherMutex.unlock();
}