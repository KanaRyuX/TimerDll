// TimerDll.cpp
// compile with: /EHsc /LD

#include "TimerDll.h"

#include <stdexcept>
#include <time.h>

using namespace std;

namespace MyTimer
{
	Timer::Timer( bool start )
	{
		if (start)
		{
			Start();
		}
		else
		{
			mBeginningTime = 0;
			mLastTime = 0;
			mStarted = false;
		}
	}

	void Timer::Start()
    {
        mBeginningTime = clock();
		mLastTime = mBeginningTime;
		mStarted = true;
    }

	void Timer::Reset()
	{
		if (mStarted)
		{
			mEndTime = clock();
			mBeginningTime = mEndTime;
			mStarted = true;
		}
		else
		{
			Start();
		}
	}

    void Timer::Stop()
    {
		mBeginningTime = 0;
        mStarted = false;
    }

	Time Timer::StartTime()
	{
		return Time(mBeginningTime);
	}

    Time Timer::ElapsedTime()
    {
        return Time(clock() - mBeginningTime);
    }

    Time Timer::DeltaTime()
    {
		clock_t tempTime = mLastTime;
		mLastTime = clock();

        return Time(mLastTime - tempTime);
    }

	Time Timer::EndTime()
	{
		return Time(mEndTime);
	}

	bool Timer::IsRunning()
	{
		return mStarted;
	}

	bool Timer::RanLongerThan( float milliseconds )
	{
		return (((float)(clock() - mBeginningTime)) / ((float)CLOCKS_PER_SEC) * 1000.0f) > milliseconds;
	}
}