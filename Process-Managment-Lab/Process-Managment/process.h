#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Process {
private:
	//variables of object
	int jobNumber, jobPriority, turnAroundTime, startTime, completionTime, executionTime, arrivalTime;
	bool arrived, executed;
public:
	//constructors
	Process() :jobNumber(0), arrivalTime(0), jobPriority(0), turnAroundTime(0), startTime(0), completionTime(0), executionTime(0), arrived(false), executed(false) {} //default constructor
	Process(int executionTime, int arrivalTime, int jobPriority, int jobNumber) :jobNumber(jobNumber), jobPriority(jobPriority), arrivalTime(arrivalTime), executionTime(executionTime), 
		turnAroundTime(0), startTime(0), completionTime(0), arrived(false), executed(false) {} //constructor with 3 inputted variables from user
	//get methods
	int getjobNumber() { return jobNumber; }
	int getjobPriority() { return jobPriority; }
	int getturnaroundTime() { return turnAroundTime; }
	int getstartTime() { return startTime; }
	int getcompletionTime() { return completionTime; }
	int getexecutionTime() { return executionTime; }
	int getarrivalTime() { return arrivalTime; }
	bool getArrived() { return arrived; }
	bool getExecuted() { return executed; }
	//set methods
	void setJobNumber(int jobNumber) { this->jobNumber = jobNumber; }
	void setJobPriority(int jobPriority) { this->jobPriority = jobPriority; }
	void setTurnAroundTime(int turnAroundTime) { this->turnAroundTime = turnAroundTime; }
	void setStartTime(int startTime) { this->startTime = startTime; }
	void setCompletionTime(int completionTime) { this->completionTime = completionTime; }
	void setExecutionTime(int executionTime) { this->executionTime = executionTime; }
	void setArrivalTime(int arrivalTime) { this->arrivalTime = arrivalTime; }
	void setArrived(bool arrived) { this->arrived = arrived; }
	void setExecuted(bool executed) { this->executed = executed; }
	//decrement of execution time
	void decrementtime() { executionTime--; }
	//operator overload
	friend ostream& operator<<(ostream& os, const Process& process)
	{
		os<< setw(5) << process.jobNumber +1 << setw(20) << process.arrivalTime << setw(20) << process.startTime << setw(20) << process.jobPriority
			<< setw(20) << process.completionTime << setw(20) << process.turnAroundTime << setw(20) << process.executionTime << setw(20) << process.executed << endl;
		return os;
	}
};
