#ifndef GLOBALMUTEX_HPP
#define GLOBALMUTEX_HPP

#include <iostream>
#include <functional>
#include <thread>
#include <mutex>


class GlobalMutex
{
private:
	static std::mutex mStreamMutex;
	static std::mutex mOtherMutex;


public:
	GlobalMutex();
	~GlobalMutex();

	void lockStreamMutex();
	void lockOtherMutex();

	void unlockStreamMutex();
	void unlockOtherMutex();
};



#endif