#include <iostream>
#include <iomanip>
#include "Process.h"
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

//asks for user input
void inputData(vector<Process>& totalProcesses);
void outputData(vector<Process> totalProcesses, double turnaroundtime, string order);
void fcfs(vector<Process>& totalProcesses);
void sjn(vector<Process>& totalProcesses);
void priority(vector<Process>& totalProcesses);
bool compareExecution(Process p1, Process p2);
bool notArrived(vector<Process> totalProcesses);
bool comparePriority(Process p1, Process p2);
bool compareJobnum(Process p1, Process p2);
bool compareArrival(Process, Process);
int totalExectutionTime(vector<Process> totalProcesses);
int search(int jobNumber, vector<Process> totalProcesses);
char input;
//main function
int main() {

	vector<Process> totalProcesses;
	totalProcesses.push_back(Process(3, 2, 3, 1));
	totalProcesses.push_back(Process(4, 2, 2, 2));
	totalProcesses.push_back(Process(1, 3, 1, 3));
	totalProcesses.push_back(Process(2, 5, 3, 4));
	//inputData(totalProcesses);

	cout << "Enter a algorithim (f for fcfs, s for sjn, p for priority): ";
	cin >> input;

	cout << endl;
	switch (input)
	{
		case 'f':
		case 'F':
			fcfs(totalProcesses);
			break;
		case 's':
		case 'S':
			sjn(totalProcesses);
			break;
		case 'p':
		case 'P':
			priority(totalProcesses);
			break;
	}

	return 0;
}

//function def for input data
void inputData(vector<Process>& totalProcesses) {
	//variables for inputs needed to eliminate more thsn necessary cout statements
	string dataNeeded[]{ "Required Time", "Arrival Time", "Priority" };
	int reqTime = 0, arrivalTime = 0, priority = 0;
	int data[]{ reqTime, arrivalTime, priority };

	int totalJobs = 0;
	//ask for total jobs
	cout << "Input the amount of processes: ";
	cin >> totalJobs;
	cout << endl;

	for (int i = 0; i < totalJobs; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Please input the " << dataNeeded[j] << " of job " << i + 1 << ": ";
			cin >> data[j];
		}
		cout << "----------------------------------------------" << endl;
		totalProcesses.push_back(Process(data[0], data[1], data[2], i));
	}

}

//output data
void outputData(vector<Process> totalProcesses, double turnaroundtime, string order) {
	//create headers table
	cout << "Job Number" << setw(20) << "Arrival Time" << setw(20) << "Start Time" << setw(20) << "Priority" << setw(20)
		<< "Completion Time" << setw(20) << "Turn Around Time" << setw(20) << "Execution Time" << setw(20) << "Executed" << endl;
	//loop to output each process
	for (auto& process : totalProcesses)
	{
		cout << process;
	}

	cout << "Average turnaround time per job was: " << turnaroundtime << endl;
	//output order of execution
	cout << order << endl;
}

//first come first serve

void fcfs(vector<Process>& totalProcesses) {
	//sort jobs by arrival times
	sort(totalProcesses.begin(), totalProcesses.end(), compareArrival);

	//some vars
	double avgturnaroundtime = 0.0;

	//first find completion time
	totalProcesses[0].setCompletionTime(totalProcesses[0].getarrivalTime() + totalProcesses[0].getexecutionTime());
	totalProcesses[0].setStartTime(totalProcesses[0].getarrivalTime());
	totalProcesses[0].setTurnAroundTime(totalProcesses[0].getcompletionTime() - totalProcesses[0].getarrivalTime());
	avgturnaroundtime += totalProcesses[0].getturnaroundTime();

	string output = "The order of execution is: " + to_string(totalProcesses[0].getjobNumber());
	//calculate values of rest of times
	for (int i = 1; i < totalProcesses.size(); i++)
	{
		//calculate completion time
		totalProcesses[i].setCompletionTime(totalProcesses[i - 1].getcompletionTime() + totalProcesses[i].getexecutionTime());
		//calcualte eahc process start time
		totalProcesses[i].setStartTime(totalProcesses[i - 1].getcompletionTime());
		//calculate each process turna around time
		totalProcesses[i].setTurnAroundTime(totalProcesses[i].getcompletionTime() - totalProcesses[i].getarrivalTime());
		//calculate avg turn around times
		avgturnaroundtime += totalProcesses[i].getturnaroundTime();
		output += " -> " + to_string(totalProcesses[i].getjobNumber());
	}
	avgturnaroundtime /= totalProcesses.size();
	//output this algorithims data
	outputData(totalProcesses, avgturnaroundtime, output);


}

//shortest job next
void sjn(vector<Process>& totalProcesses) {
	//sort jobs by arrival times
	sort(totalProcesses.begin(), totalProcesses.end(), compareArrival);

	//temp vector for running through arrived jobs
	vector<Process> temp;
	//calculate how long the total time of execution should be
	int totaltime = totalExectutionTime(totalProcesses) + totalProcesses[0].getarrivalTime();
	int runUntil = 0;
	int currentlyRunning = 0;
	int current = 0;
	double turnaroundtime = 0.0;
	string output = "The order of execution is: ";
	//loop to represent real time os
	for (int i = 1; i <= totaltime; i++)
	{
		//check if there are processes that have not arrived
		if (!notArrived(totalProcesses))
		{
			//loop to see if any jobs arrive at this time
			for (auto process : totalProcesses)
			{
				//if a job has arrived add it to the vector
				if (process.getarrivalTime() == i && !process.getArrived())
				{
					process.setArrived(true);
					temp.push_back(process);
					sort(temp.begin(), temp.end(), compareExecution);
				}
			}
		}

		//sort the existing jobs by execution time if more than one job exists
		if (runUntil == i)
		{
			runUntil = 0;
			current = search(currentlyRunning, temp);
			temp[current].setCompletionTime(i);
			temp[current].setExecuted(true);
			temp[current].setTurnAroundTime(i - temp[current].getarrivalTime());
			turnaroundtime += temp[current].getturnaroundTime();
		}

		if (runUntil == 0 && temp.size() > 1)
		{
			//for (auto process: temp)
			for (int j = 0; j < temp.size(); j++)
			{
				if (!temp[j].getExecuted())
				{
					runUntil = i + temp[j].getexecutionTime();
					currentlyRunning = temp[j].getjobNumber();
					temp[j].setStartTime(i);
					output += " -> " + to_string(temp[j].getjobNumber());
					break;
				}
			}

		}





	}
	turnaroundtime /= temp.size();
	sort(temp.begin(), temp.end(), compareJobnum);
	outputData(temp, turnaroundtime, output);

}


//priority 
void priority(vector<Process>& totalProcesses) {
	//sort jobs by arrival times
	sort(totalProcesses.begin(), totalProcesses.end(), compareArrival);

	//temp vector for running through arrived jobs
	vector<Process> temp;
	//dummy job
	//Process* currentJob = new Process(1, 1, 1, -1);
	//calculate how long the total time of execution should be
	int totaltime = totalExectutionTime(totalProcesses) + totalProcesses[0].getarrivalTime();
	double turnaroundtime = 0.0;
	string output = "The order of execution is: ";
	bool newArrived = false;
	int currentlyrunning = -1;
	int current = 0;
	bool jobrunning = false;
	//loop to represent real time os
	for (int i = 1; i <= totaltime; i++)
	{
		
		//check if there are processes that have not arrived
		if (!notArrived(totalProcesses) && temp.size() != totalProcesses.size())
		{
			//loop to see if any jobs arrive at this time
			for (auto& process : totalProcesses)
			{
				//if a job has arrived add it to the vector
				if (process.getarrivalTime() == i && !process.getArrived())
				{
					process.setArrived(true);
					temp.push_back(process);
					sort(temp.begin(), temp.end(), comparePriority);
					current = search(currentlyrunning, temp);
					if (jobrunning)
					{
						if (temp[current] != temp.front())
						{
							newArrived = true;
						}
					}

				}
			}
		}
		//only enter if jobs have arrived
		if (temp.size() > 0)
		{

			if (currentlyrunning != -1)
			{
				//decrements time if a job is running
				if (temp[current].getstartTime() != i && temp[current].getexecutionTime() != 0)
				{
					temp[current].decrementtime();
				}
			}

			//sets a job if one has conculded or none are running
			if (temp[current].getexecutionTime() == 0 || currentlyrunning == -1)
			{
				//if a job is running it finishes that job
				if (currentlyrunning != -1)
				{
					temp[current].setCompletionTime(i);
					temp[current].setExecuted(true);
					temp[current].setTurnAroundTime(i - temp[current].getarrivalTime());
					turnaroundtime += temp[current].getturnaroundTime();
					output += " -> " + to_string(temp[current].getjobNumber());
				}
				//check which job is next up
				for (auto& process : temp)
				{
					if (!process.getExecuted())
					{

						currentlyrunning = process.getjobNumber();
						current = search(currentlyrunning, temp);
						if (temp[current].getstartTime() == 0)
							temp[current].setStartTime(i);
						jobrunning = true;
						break;
					}

				}

			}
			//set new job to execute if a higher priority arrived
			if (newArrived && temp[current] != temp.front())
			{
				for (auto& process : temp)
				{
					if (!process.getExecuted())
					{
						currentlyrunning = process.getjobNumber();

						current = search(currentlyrunning, temp);
						if (temp[current].getstartTime() == 0)
							temp[current].setStartTime(i);
						break;
					}

				}
			}



		}
		newArrived = false;
	}

	turnaroundtime /= temp.size();
	sort(temp.begin(), temp.end(), compareJobnum);
	outputData(temp, turnaroundtime, output);
}



//compare priority
bool comparePriority(Process p1, Process p2) {
	return p1.getjobPriority() < p2.getjobPriority();
}

//compare arrival times for sort method
bool compareArrival(Process p1, Process p2) {
	return p1.getarrivalTime() < p2.getarrivalTime();
}

//compare execution times
bool compareExecution(Process p1, Process p2) {
	return p1.getexecutionTime() < p2.getexecutionTime();
}

//compare job numbers just for outputs
bool compareJobnum(Process p1, Process p2) {
	return p1.getjobNumber() < p2.getjobNumber();
}


//funciton that checks if theyre are still jobs that havent arrived
bool notArrived(vector<Process> totalProcesses) {
	bool notArrived = true;
	//loop to check
	for (auto process : totalProcesses) {
		if (!process.getArrived())
			notArrived = false;
	}
	return notArrived;
}
//calculate total execution time
int totalExectutionTime(vector<Process> totalProcesses) {
	int totaltime = 0;
	for (auto process : totalProcesses)
	{
		totaltime += process.getexecutionTime();
	}
	return totaltime;
}

//returns index of element based off job name
int search(int jobNumber, vector<Process> temp)
{
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getjobNumber() == jobNumber)
		{
			return i;
		}

	}
}