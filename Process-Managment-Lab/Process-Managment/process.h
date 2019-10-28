#include <iostream>
#include <string>
using namespace std;

#pragma once
class Process {
	private:
	//variables of object
	int jobNumber, jobPriority, turnAroundTime, startTime, completionTime, executionTime, arrivalTime;
	public:
	//constructors
	Process():jobNumber(-1), arrivalTime(-1), jobPriority(-1), turnAroundTime(-1), startTime(-1), completionTime(-1), executionTime(-1) {} //default constructor
	Process(int executionTime,int arrivalTime, int jobPriority, int jobNumber):jobNumber(jobNumber), jobPriority(jobPriority), arrivalTime(arrivalTime), executionTime(executionTime) {} //constructor with 3 inputted variables from user
	//get methods
	int getJobNumber() { return jobNumber; }
	int getJobPriority() { return jobPriority; }
	int turnAroundTime() { return turnAroundTime; }
	int getStartTime() { return startTime; }
	int getCompletionTime() { return completionTime; }
	int getExecutionTime() { return executionTime; }
	int getArrivalTime() { return arrivalTime; }
	//set methods
	void setJobNumber(int jobNumber) { this->jobNumber= jobNumber; }
	void setJobPriority(int jobPriority) { this->jobPriority = jobPriority;}
	void setTurnAroundTime(int turnAroundTime) { this->turnAroundTime = turnAroundTime; }
	void setStartTime(int startTime) { this->startTime = startTime; }
	void setCompletionTime(int completionTime) { this->completionTime = completionTime; }
	void setExecutionTime(int executionTime) { this->executionTime = executionTime; }
	void setArrivalTime(int arrivalTime) { this->arrivalTime = arrivalTime; }
	//operator overload
	friend ostream& operator<<(ostream& os, const Process& process)
	{
		os << process.jobNumber << endl;
		os << process.jobPriority << endl;
		os << process.arrivalTime << endl;
		os << process.executionTime << endl;
		os << process.turnAroundTime << endl;
		os << process.startTime << endl;
		os << process.completionTime << endl;
		return os;
	}

};
