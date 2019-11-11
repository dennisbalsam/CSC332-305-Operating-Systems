#include <iostream>
#include <iomanip>
#include "Process.h"
#include <vector>
#include<algorithm>
using namespace std;

//asks for user input
void inputData(vector<Process>& totalProcesses);
void outputData(vector<Process> totalProcesses, double turnaroundtime);
void fcfs(vector<Process>& totalProcesses);
bool compareArrival(Process, Process);
//main function
int main() {

	vector<Process> totalProcesses;
	inputData(totalProcesses);
	fcfs(totalProcesses);
	//outputData(totalProcesses);
	
	return 0;
}

//function def for input data
void inputData(vector<Process>& totalProcesses) {
	//variables for inputs needed to eliminate more thsn necessary cout statements
	string dataNeeded[] { "Required Time", "Arrival Time", "Priority" };
	int reqTime =0 , arrivalTime=0, priority=0;
	int data[]{reqTime, arrivalTime, priority };

	int totalJobs = 0;
	//ask for total jobs
	cout << "Input the amount of processes: ";
	cin >> totalJobs;
	cout << endl;

	for (int i = 0; i < totalJobs; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Please input the " << dataNeeded[j] << " of job " << i+1 << ": ";
			cin >> data[j];
		}
		cout << "----------------------------------------------" << endl;
		totalProcesses.push_back(Process(data[0], data[1], data[2], i));
	}
}

//output data
void outputData(vector<Process> totalProcesses,  double turnaroundtime){
	//create headers table
	cout <<  "Job Number" << setw(20) << "Arrival Time" << setw(20) << "Start Time" << setw(20) << "Completion Time" << setw(20) << "Turn Around Time" << setw(20) << "Execution Time"<<   endl;
	//loop to output each process
	for (auto& process : totalProcesses)
	{
		cout << process;
	}
	cout << "Average turnaround time per job was: " << turnaroundtime << endl;
}



void fcfs(vector<Process>& totalProcesses) {
	//sort jobs by arrival times
	sort(totalProcesses.begin(), totalProcesses.end(), compareArrival);

	//some vars
	double avgturnaroundtime = 0.0;

	//first find completion time
	totalProcesses[0].setCompletionTime(totalProcesses[0].getarrivalTime() + totalProcesses[0].getexecutionTime());
	totalProcesses[0].setStartTime(totalProcesses[0].getarrivalTime());
	totalProcesses[0].setTurnAroundTime(totalProcesses[0].getcompletionTime() - totalProcesses[0].getarrivalTime());
	
	//calculate values of rest of times
	for (int i = 1; i < totalProcesses.size(); i++)
	{
		//ct[i] = ct[i - 1] + bt[i];
		totalProcesses[i].setCompletionTime(totalProcesses[i - 1].getcompletionTime() + totalProcesses[i].getexecutionTime());
		totalProcesses[i].setStartTime(totalProcesses[i - 1].getcompletionTime());
		//turnaroundtime[i] = ct[i] - at[i];
		//wt[i] = turnaroundtime[i] - bt[i];
		//awt = awt + wt[i];
		//atat = atat + turnaroundtime[i];
		totalProcesses[i].setTurnAroundTime(totalProcesses[i].getcompletionTime() - totalProcesses[i].getarrivalTime());
		avgturnaroundtime += totalProcesses[i].getturnaroundTime();
	}
	avgturnaroundtime /= totalProcesses.size();

	outputData(totalProcesses, avgturnaroundtime);


}

bool compareArrival(Process p1, Process p2)
{
	return (p1.getarrivalTime() < p2.getarrivalTime());
}