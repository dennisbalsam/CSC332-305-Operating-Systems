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
//first fit algorithim
void firstFitAlgorithim(vector<Memory>& mainMemory, vector<Process>& processes);
//worst fit algorithim
void worstFitAlgorithim(vector<Memory>& mainMemory, vector<Process>& processes);
//function to output data
void outputMemory(vector<Memory> mainMemory, vector<Process> processes, string algorithim);

int main()
{
	//define a vector to serve as the main memory
	vector<Memory> mainMemory;
	vector<Process> processes;

	//ask for user input for partitions and memory information
	//functions to ask for user input for memory partitions and size of each partition
	memorySlots(mainMemory);
	//functions to ask for process amount and size of each process
	processInfo(processes);

	//ask user what algorithim user wants to sort by 
	char input;
	cout << "What algorithim would you like to use?: ";
	cin >> input;
	cout << endl;
	
	system("cls");
	//switch statement 
	switch (input)
	{
	case 'f': 
	case 'F':
		//call first fit algorithim
		firstFitAlgorithim(mainMemory, processes);
		break;
	case 'w':
	case 'W':
		//call first fit algorithim
		worstFitAlgorithim(mainMemory, processes);
		break;
	default:
		cout << "Wrong Letter Entry" << endl;
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
		//create the object
		Memory tempObj =  Memory(memory);
		mainMemory.push_back(tempObj);
	}
	cout << endl;
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
	int processSize = 0;
	for (int x = 0; x < processesNum; x++)
	{
		int processSize = 0;
		//ask for process size
		cout << "Enter the size of process #" << x + 1 << ": ";
		cin >> processSize;

		//create the process object
		string jobName;
		jobName = "Job #" + to_string(x + 1);
		Process tempObj = Process(jobName, false, -1, processSize);

		//add it to the vector
		processes.push_back(tempObj);
	}
}

//------------------------------------------------------------------first fit algorithim-----------------------------------------------------------------

//first fit algorithim
void firstFitAlgorithim(vector<Memory>& mainMemory, vector<Process>& processes)
{
	Process emptyJob; 
	//nested loop for each process we have
	for (int x = 0; x < processes.size(); x++)
	{
			for (int y = 0; y < mainMemory.size(); y++)
			{
				if (mainMemory[y].getJob() == emptyJob && mainMemory[y].getSize() >= processes[x].getjobSize() && processes[x].getPartition() == -1)
				{
					//assign job to memory slot and set process partition number
					processes[x].setPartition(y);
					//put process in run state
					processes[x].setStatus(true);
					mainMemory[y].setJob(processes[x]);	
				}
			}
	}
	outputMemory(mainMemory, processes, "FIRST FIT ALGORITHIM");
}


//function to output current data
void outputMemory(vector<Memory> mainMemory, vector<Process> processes, string algorithim)
{
	
	//output algorithim name
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << algorithim << endl;
	
	//define variables needed
	Process emptyJob;
	int memorySlot = 1;
	int totalUsed = 0;
	int totalAvailable = 0;
	int wastedMem = 0;
	//loop over each memory slot
	for (auto& partition : mainMemory) //loop through each memory slot
	{
		//add total memory size
		totalAvailable += partition.getSize();
		//add total memory used
		totalUsed += partition.getJob().getjobSize();
		//output data

		//if partition isnt used it is not waste
		if (partition.getJob() == emptyJob)
		{
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "Memory Slot " << memorySlot << " does not have a job" << endl;
			cout << "This slot is not used so there is no waste" << endl;
		}
		else
		{
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "Memory Slot " << memorySlot << " has " << partition.getJob().getName() << endl;
			if (partition.getJob().getStatus())
			{
				cout << partition.getJob().getName() << " is running: true"<< endl;
			}
			wastedMem += partition.getSize() - partition.getJob().getjobSize();
			cout << "Total Memory Waste in this slot is: " << partition.getSize() - partition.getJob().getjobSize() << endl;
		}
		memorySlot++;
	}
	//check what job is not assigned
	for (auto& partition : processes) //loop through each job
	{
		if (partition.getPartition() == -1)
		{
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << partition.getName() << " is not assigned, it is in waiting state" << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Total amount of storage that was available: " << totalAvailable << endl;
	cout << "Total Amount of Storage that was used: " << totalUsed << endl;
	cout << "Total Amount of Storage that was wasted: " << wastedMem << endl;
}


//-----------------------------------------------------------------worst fit algorithim---------------------------------------------------------------------
void worstFitAlgorithim(vector<Memory>& mainMemory, vector<Process>& processes)
{
	//define an empty job for comparison
	Process emptyJob;
	//loop over jobs and partitions to see which is the worst fit
	for (int x = 0; x < mainMemory.size(); x++)
	{
		int diff = -1; // diff. bewteen partition size and job size
		int largestdiff = -1; // largest diff. found
		int bestpartition = -1; // index of partition with largest diff.

		for (int y = 0; y < processes.size(); y++)
		{
			// if partition is empty and job can fit in part.
			if (mainMemory[y].getJob() == emptyJob && mainMemory[y].getSize() >= processes[x].getjobSize() && processes[x].getPartition() == -1)
			{
				diff = mainMemory[x].getSize() - processes[y].getjobSize();
				// if largestdiff is unitialized or diff is larger than largestdiff
				if (largestdiff < 0 || diff >= largestdiff)
				{
					largestdiff = diff;
					bestpartition = y;
				}
			}
		}
		cout << "Best Partition: " << bestpartition << endl;
		// if a largestdiff was found for current job
		if (largestdiff > -1)
		{
			//give the job the partition number
			processes[x].setPartition(bestpartition);
			processes[x].setStatus(true); // set job status
			 // set job  for partition
			mainMemory[bestpartition].setJob(processes[x]);
		}
	}

	//output the results
	outputMemory(mainMemory, processes, "WORST FIT ALGORITHIM");
}