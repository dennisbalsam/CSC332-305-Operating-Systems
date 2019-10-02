#include <iostream>
#include <vector>
#include "process.h"
#include "memory.h"
#include <sstream>
using namespace std;


//function for amount of partitions
void processInfo(vector<Process>& processes);
//function for input of memory size of each partition
void memorySlots(vector<Memory>& mainMemory);

int main()
{
	//define a vector to serve as the main memory
	vector<Memory> mainMemory;
	vector<Process> processes;
	
	/*
	User will input to the program
		a.	 Main Memory information, including
			i.	 The Number of Memory partitions.
			ii.	The Size of each memory partition.
		b.	Process information (assign a unique identifier to each job)
			i.	User will input the number of processes
			ii.	Memory requirements for each process/job
			iii.	amount of memory each process requires

	
	*/
	//functions to ask for user input for memory partitions and size of each partition
	memorySlots(mainMemory);
	//functions to ask for process amount and size of each process
	processInfo(processes);

	
	for (auto& partition : processes) // access by reference to avoid copying
	{
		cout << partition;
	}
	


	return 0;
}


//function for input of memory size of each partition
void memorySlots(vector<Memory>& mainMemory) {
	//ask for user input for partition amount
	int partitions;
	cout << "Enter the number of Partitions in the main memory: ";
	cin >> partitions;
	cout << endl;
	//declare variable for memory size
	int memory;
	//loop the amount of times as partition size
	for (int x = 0; x < partitions; x++)
	{
		//ask for user input
		cout << "Enter partition #" << x + 1 << " memory size: ";
		cin >> memory;
		cout << endl;
		//create the object
		Memory tempObj =  Memory(memory);
		mainMemory.push_back(tempObj);
	}
}

//function to input amount of processes and size of each
void processInfo(vector<Process>& processes)
{
	//ask for user input for process amount
	int processesNum;
	cout << "Enter amount of processes: ";
	cin >> processesNum;
	cout << endl;

	//loop to ask for process size and create each process
	int processSize;
	for (int x = 0; x < processesNum; x++)
	{
		//ask for process size
		cout << "Enter the size of process #" << x + 1 << ": ";
		cin >> processSize;
		cout << endl;

		//create the process object
		string jobName;
		jobName = "Job #" + to_string(x + 1);
		Process tempObj = Process(jobName, false, 0, processSize);

		//add it to the vector
		processes.push_back(tempObj);
}

//worst fit algorithim





}