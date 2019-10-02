#include <iostream>
#include "process.h"
using namespace std;

class Memory {
private:
	//composition for process in the memory
	Process job;
	//memory size 
	int size;
public:
	//default constructor
	Memory();
	//constructor with just memory size
	Memory(int size);
	//constructor with the memory size and job variabled
	Memory(int size, string name, bool status, int partition, int jobSize);
	//operator overload
	friend ostream& operator<<(ostream& os, const Memory& memory);

	//get and set size 
	void setSize(int size) { this->size = size; }
	int getSize() { return size; }


};