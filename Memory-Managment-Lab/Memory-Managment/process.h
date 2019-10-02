#pragma once

#include <iostream>
using namespace std;
class Process {
	private:
		//variable for process name
		string name;
		//variable for the job status
		bool status;
		//variable for partition number
		int partition;
		//size of the job
		int jobSize;
	public:
		//default constructor
		Process();
		//constructor with 3 parameters
		Process(string name, bool status, int partition, int jobSize);
		//get functions
		string getName() { return name; }
		bool getStatus() { return status; }
		int getPartition() { return partition; }
		int getjobSize() { return jobSize; }
		//set functions
		void setName(string name) { this->name = name; }
		void setStatus(bool status) { this->status = status; }
		void setPartition(int partition) { this->partition = partition; }
		void setjobSize(int jobSize) { this->jobSize = jobSize; }
		//operator overload
		friend ostream& operator<<(ostream& os, const Process& job);
		friend bool operator==(const Process& jobOne, const Process& jobTwo);





		
};
