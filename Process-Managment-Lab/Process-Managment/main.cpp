#include <iostream>
#include "process.h"
#include <vector>
using namespace std;

//asks for user input
void inputData(vector<Process>& totalProcesses);

int main() {

	vector<Process> totalProcesses;

	return 0;
}

//function def for input data
void inputData(vector<Process>& totalProcesses) {
	//variables for inputs needed to eliminate more thsn necessary cout statements
	string dataNeeded[] { "Required Time", "Arrival Time", "Priority" };
	int reqTime, arrivalTime, priority;
	int data[]{ reqTime, arrivalTime, priority };

	int totalJobs = 0;
	//ask for total jobs
	cout << "Input the amount of processes";
	cin >> totalJobs;
	cout << endl;

	for (int i = 0; i < totalJobs; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Please input the " << dataNeeded[j] << " of job " << i << endl;
			cin >> data[j];
			cout << endl;
		}
		totalProcesses.push_back(Process(data[0], data[1], data[2], i));
	}
}