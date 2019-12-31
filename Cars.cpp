#include "Cars.h"




Cars::Cars() {};

Cars::Cars(int arrivalTime, int washStartTime) {
	this->arrivalTime = arrivalTime;
	this->washStartTime = washStartTime;
	setDepartureTime(washStartTime + 3);
	setWaitTime(arrivalTime, washStartTime);    //wait and depart times are calcd on object creation
	setTotalTime(this->departureTime, arrivalTime);    //car object is only created once it enters the car wash
	carCount += 1;
	setCarNumber(carCount);
	totalWaitTime += this->waitTime;
	totalWashTime += 3;
	avgWaitTime = totalWaitTime / carCount;
	washUsePercent = totalWashTime / 540.0 * 100.0;

	std::cout << this->carNumber << "\t\t" << arrivalTime << "\t\t" << washStartTime
		<< "\t\t" << departureTime << "\t\t" << waitTime << "\t\t" << totalTime << "\n\n";
}//end constructor

Cars::Cars(int arrivalTime, bool afterClosing) { //constructor for late cars
	carCount += 1;
	setCarNumber(carCount);
	std::cout << this->carNumber << "\t\t" << arrivalTime << "\t\t" << "Car arrived after closing time and was not served.\n\n";
}//end constructor for late cars

void Cars::setCarNumber(const int number) {
	carNumber = number;
}//end setCarNumber

void Cars::setWashStartTime(const int washTime) {
	washStartTime = washTime;
}//end setWashStartTime

void Cars::setDepartureTime(const int departTime) {
	departureTime = departTime;
}//end setDepartureTime

void Cars::setWaitTime(const int arrivalTime, const int washStartTime) {
	waitTime = washStartTime - arrivalTime;
}//end setWaitTime

void Cars::setTotalTime(const int departureTime, const int arrivalTime) {
	totalTime = departureTime - arrivalTime;
}//end setTotalTime

int Cars::getCarNumber() {
	return carNumber;
}//end getCarNumber

int Cars::getWashStartTime() {
	return washStartTime;
}//end getWashStartTime

int Cars::getDepartureTime() {
	return departureTime;
}//end getDepartureTime

int Cars::getWaitTime() {
	return waitTime;
}//end getWaitTime

int Cars::getCarCount() {
	return carCount;
}//end getCarCount

int Cars::getTotalTime() {
	return totalTime;
}//end getTotaltime

