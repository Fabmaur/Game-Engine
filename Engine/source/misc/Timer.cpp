#include "pch.h"
#include "Timer.h"

namespace misc
{
	Timer::Timer()
		:timeElapsed(0.0f)
	{
		start = std::chrono::steady_clock::now();
	}

	int Timer::getFPS()
	{
		/* Checks the difference between the last time and the
		current time and stores it in timeElapsed*/
		auto lastStart = start;
		start = std::chrono::steady_clock::now();
		timeElapsed = start - lastStart;
	
		return  int(1 / timeElapsed.count());
	}
}