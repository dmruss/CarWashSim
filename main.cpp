#include "Cars.h"


//Global Variables and Functions
const int SIMULATION_END_TIME = 540;
int currentTime = 0;
std::queue<int> arrivalTime; //holds all car arrival times from input file
std::vector<Cars> visitedCarWash;  //holds all car objects that have been to the car wash
bool washFull(); //checks if wash is full


//Initialize Class variables
double Cars::carCount = 0;
double Cars::totalWaitTime = 0;
double Cars::totalWashTime = 0;
double Cars::avgWaitTime = 0.0;
double Cars::washUsePercent = 0.0;

int main() {
	std::cout << "Opening time: 8:00 AM (0 minutes)\n";
	std::cout << "Closing time: 5:00 PM (540 minutes)\n";
	std::cout << "Start of Simulation\n\n";

	//read in all entries from file into the queue
	std::ifstream infile("arrival_time.txt");
	int times;//used to read in file
	while (!infile.eof()) {


		infile >> times;
		arrivalTime.push(times);
		
	}
	infile.close();

	//Table Formatting
	std::cout << "Car Number\tArrivalTime\tCar Wash\tDeparture Time\tWaitTime\tTotal\n";
	std::cout << "\t\t\t\tStart Time\t\t\t\t\tTime\n\n";
	

	//Car Wash Loop Prints out each car that arrives at car wash
	while (!arrivalTime.empty()) {

		if (arrivalTime.front() > SIMULATION_END_TIME) { //checking if car arrived after closing
			Cars::Cars(arrivalTime.front(), true);
			arrivalTime.pop();
		}

		else if (!washFull() && arrivalTime.front() <= currentTime) {
			visitedCarWash.push_back(Cars::Cars(arrivalTime.front(), currentTime));  //Car sits in queue until added to vector when it goes into car wash
			arrivalTime.pop();	
		
		}//end sending cars into car wash

		currentTime++;

	}//end car wash loop


	std::cout << "End of Simulation \n\n\n";

	//Read Car wash statistics
	std::cout << "Statistics: \n\n";
	std::cout << "Total wait time: " << Cars::totalWaitTime << " minutes\n\n";
	std::cout << "Average wait time: " << int(Cars::avgWaitTime * 60)/60 << " minutes and " << int(Cars::avgWaitTime * 60) % 60 << " seconds" << "\n\n";
	std::cout.precision(3);
	std::cout << "Total car wash use time: " << Cars::totalWashTime << " minutes\n\n";
	std::cout.precision(2);
	std::cout << "Percentage of time car wash was in use: " << Cars::washUsePercent << "%\n\n";


return 0;
}



bool washFull() {
	if (Cars::carCount == 0)  //need this to avoid a negative vector index error
		return false;
	//if the most recently added car in the vector started its wash 3 or more minutes ago then the wash is empty
	else if ((currentTime - (visitedCarWash[Cars::carCount - 1].getWashStartTime())) >= 3)
		return false;
	else   
		return true;
	
}//end washFull

