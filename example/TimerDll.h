// TimerDll.h
#pragma once

#include "Time.h"

namespace MyTimer
{
    class Timer
    {
    public:
		// Creates a timer. Pass a true parameter to start the timer immediately.
		__declspec(dllexport) Timer( bool start );

		// Destroys the timer.
		__declspec(dllexport) ~Timer() {};

        // Starts the timer. Needed to use DeltaTime and ElapsedTime.
        __declspec(dllexport) void Start();

		// Restarts the timer.
		__declspec(dllexport) void Reset();

        // Stops the timer.
        __declspec(dllexport) void Stop();

		// Returns the time the timer started. Will return a time of 0 if timer hasn't been started yet.
		__declspec(dllexport) Time StartTime();

        // Returns time since start of timer.
        __declspec(dllexport) Time ElapsedTime();

        // Returns time since last call of DeltaTime. If it's the first call, it uses the start time as the last time.
        __declspec(dllexport) Time DeltaTime();

		// If you have Reset or Stopped the timer this is the time when the timer was reset or ended. Otherwise it will return a Time of 0.
		__declspec(dllexport) Time EndTime();

		// Returns true if Timer has been started.
		__declspec(dllexport) bool IsRunning();

		// Returns true if time since start is greater than milliseconds
		__declspec(dllexport) bool RanLongerThan( float milliseconds );

	private:
		clock_t mBeginningTime;
		clock_t mLastTime;
		clock_t mEndTime;
		bool mStarted;
    };
}