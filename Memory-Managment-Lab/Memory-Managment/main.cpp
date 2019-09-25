#include <iostream>
#include "process.h"
using namespace std;

int main()
{
	Process x;
	Process y("dennis", true, 1);

	cout << x;
	cout << y;
	/*
	User will input to the program
		a.	 Main Memory information, including
			i.	 The Number of Memory partitions.
			ii.	The Size of each memory partition.
		b.	Process information (assign a unique identifier to each job)
			i.	User will input the number of processes
			ii.	Memory requirements for each process/job
			iii.	amount of memory each process requires

	
	*/




	return 0;
}