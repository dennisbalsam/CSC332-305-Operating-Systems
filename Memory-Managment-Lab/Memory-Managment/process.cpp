#include "process.h"

//defualt constructor
Process::Process():name(" "), status(false), partition(0) {}
//constructor with 3 parameters
Process::Process(string name, bool status, int partition): name(name), status(status), partition(partition){}
//operator overload
ostream& operator<<(ostream& os, const Process& job)
{
	os << job.name << endl;
	os << job.status << endl;
	os << job.partition << endl;
	return os;
}
