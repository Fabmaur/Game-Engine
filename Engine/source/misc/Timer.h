#pragma once
#include <chrono>

namespace misc
{
	class Timer
	{
	public:
		Timer();
		int getFPS();

	private:
		std::chrono::duration<float> timeElapsed;
		std::chrono::steady_clock::time_point start;
	};
}