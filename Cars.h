#ifndef _CARS
#define _CARS

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

class Cars
{

private:
	int carNumber, arrivalTime, washStartTime, departureTime, waitTime, totalTime;
	bool afterClosing;
	
public:
	static double carCount;
	static double totalWaitTime, totalWashTime;
	static double avgWaitTime, washUsePercent;
	Cars();
	Cars(int arrivalTime, int washStartTime);
	Cars(int arrivalTime, bool afterClosing);
	void setCarNumber(const int number);
	void setWashStartTime(const int washTime);
	void setDepartureTime(const int departTime);
	void setWaitTime(const int arrivalTime, const int washStartTime);
	void setTotalTime(const int departureTime, const int arrivalTime);
	int getCarNumber();
	int getWashStartTime();
	int getDepartureTime();
	int getWaitTime();
	int getCarCount();
	int getTotalTime();

};


#endif