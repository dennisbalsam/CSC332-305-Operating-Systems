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
	public:
		//default constructor
		Process();
		//constructor with 3 parameters
		Process(string name, bool status, int partition);
		//get functions
		string getName() { return name; }
		bool getStatus() { return status; }
		int getPartition() { return partition; }
		//set functions
		void setName(string name) { this->name = name; }
		void setStatus(bool status) { this->status = status; }
		void setPartition(int partition) { this->partition = partition; }
		//operator overload
		friend ostream& operator<<(ostream& os, const Process& job);





		
};
