#include <iostream>
#include <iomanip>
#include "Process.h"
#include <vector>
#include<algorithm>
using namespace std;

//asks for user input
void inputData(vector<Process>& totalProcesses);
void outputData(vector<Process> totalProcesses);
void fcfs(vector<Process>& totalProcesses);

//main function
int main() {

	vector<Process> totalProcesses;
	inputData(totalProcesses);
	fcfs(totalProcesses);
	outputData(totalProcesses);
	
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
void outputData(vector<Process> totalProcesses){
	//create headers table
	cout <<  "Job Number" << setw(20) << "Arrival Time" << setw(20) << "Start Time" << setw(20) << "Completion Time" << setw(20) << "Turn Around Time" << setw(20) << "Execution Time"<<   endl;
	//loop to output each process
	for (auto& process : totalProcesses)
	{
		cout << process;
	}
}



void fcfs(vector<Process>& totalProcesses) {
	//first find completion time
	//ct[0] = bt[0] + at[0];
	//for (i = 1; i < n; i++)
	//{
	//	ct[i] = ct[i - 1] + bt[i];
	//}

	//sort jobs for easier calculations
	sort(totalProcesses.begin(), totalProcesses.end());
	outputData(totalProcesses);

}