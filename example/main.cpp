#include "TimerDll.h"
#include "Time.h"

#include <iostream>
#include <string>

using namespace std;
using namespace MyTimer;

int main(void)
{
	Timer* myTimer = new Timer(false);
	string choice;

	while (choice != "0" )
	{
		if (choice == "s" || choice == "start")
		{
			myTimer->Start();
			cout << "Timer started at " << myTimer->StartTime().Seconds() << " seconds." << endl;
		}
		if (choice == "r" || choice == "reset")
		{
			myTimer->Reset();
			cout << "Timer reset at " << myTimer->EndTime().Seconds() << " seconds." << endl;
		}
		if (choice == "t" || choice == "time")
		{
			cout << "Time since start is " << myTimer->ElapsedTime().Seconds() << " seconds." << endl;
		}
		if (choice == "d" || choice == "delta")
		{
			cout << "Time since last delta call is " << myTimer->DeltaTime().Seconds() << " seconds." << endl;
		}

		cin >> choice;
	}

	return 0;
}