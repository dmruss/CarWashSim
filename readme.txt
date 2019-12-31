*******************************************************
*  Name      :  David Russell        
*  Student ID:  101147569     
*  Class     :  CSC 2421           
*  HW#       :  4                
*  Due Date  :  Oct. 15, 2019
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program simulates the operation of a car wash in which the wash
holds one car at a time, the wash time is 3 minutes, and the wash is open
for 540 minutes..  The arrival times of the cars are first read in 
from a .txt file into a queue, and then used to instantiate a class object which is held 
In a vector when the car enters the wash.  The details for each car are printed to the
Console when that car enters the wash.  At the end, the program reports statistics 
on total wash time, average wait time, and percentage of time the wash was in use.  

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
Main program.  This contains the organization for the simulation and the 
structure for the readout of the statistics.

Name:  Cars.h
  	Holds the Cars class declaration and function prototypes.

Name: Cars.cpp
	Contains the implementations for the Cars class functions.

arrival_time.txt
  	Contains the arrival times of each vehicle for the simulation.
   


   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Visual Studio version 16.2.3.  It was 
   compiled, run, and tested on gcc version 6.3.1 on csegrid.cudenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [russellHW4.zip]

   Now you should see a directory named homework with the files:
        main.cpp
        Cars.cpp
        Cars.h
        arrival_times.txt
        makefile
        README.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [russellHW4] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[hw4]

4. Delete the obj files, executables, and core dump by
   %./make clean
