// Time.h
#pragma once

#include <time.h>

namespace MyTimer
{
	class Time
	{
	public:
		__declspec(dllexport) Time(clock_t clock);
		__declspec(dllexport) ~Time() {};

		__declspec(dllexport) inline float Hours() { return ((float)(mClock / CLOCKS_PER_SEC)) / 60.0f / 60.0f; };
		__declspec(dllexport) inline float Minutes() { return ((float)(mClock / CLOCKS_PER_SEC)) / 60.0f; };
		__declspec(dllexport) inline float Seconds() { return ((float)(mClock / CLOCKS_PER_SEC)); };
		__declspec(dllexport) inline float Milliseconds() { return ((float)(mClock / CLOCKS_PER_SEC)) * 1000.0f; };
	private:
		clock_t mClock;
	};
}