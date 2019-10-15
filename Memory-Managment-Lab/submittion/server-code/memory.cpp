#include "memory.h"

//default constructor
Memory::Memory() : size(0)
{
	Process();
}
//constructor with one parameter
Memory::Memory(int size) : size(size)
{
	job = Process();
}

//constructor with 3 parameters
Memory::Memory(int size, string name, bool status, int partition, int jobSize): size(size)
{
	job = Process(name, status, partition, jobSize);
}

//operator overload
ostream& operator<<(ostream& os, const Memory& memory)
{
	os << memory.size << endl;
	os << memory.job << endl;
	return os;
}