#include <iostream>
#include <unistd.h>
#include <string.h>


using namespace std;

int main() {

	//parent to child pipe
	int pp2c[2];
	//child to parent pipe
	int pc2p[2];

	//declare strings to send to child and parent
	char* childMsg = "This is message from the child process";
	char* parentMag = "This is message from the parent process";



	//amount of bytes
	int bytes = 100;

	//creates pipes and places 2 file descriptor into each pipe for read and write
	//returns 0 if it successful
	pipe(pp2c);
	pipe(pc2p);

	//fork() to create the processes
	//create the process and check it is successful
	switch (fork()) {
		//this will be the child process
	case 0:
		//declare place to store message
		char recievedMsg[bytes];

		//read from the parent pipe
		read(pp2c[0], recievedMsg, bytes);
		close(pp2c[0]); //close the read connection

		//output the recieved message
		cout << "Child recieved message: " << recievedMsg << endl;


		//write a message to the child pipe
		write(pc2p[1], childMsg, strlen(childMsg) + 1);
		close(pc2p[1]); //close the write 

		//break out of switch statement
		break;
	case -1:
		cout << "failure of process" << endl;
		break;
		//parent process
	default:
		//declare place to store message
		char newMsg[bytes];


		//write a message to the parent pipe
		write(pp2c[1], parentMag, strlen(parentMag) + 1);
		close(pp2c[1]);

		//read from child pipe
		read(pc2p[0], newMsg, bytes);
		close(pc2p[0]);

		//print out the recieved message
		cout << "Parent recieving message: " << newMsg << endl;
	}


	return 0;

}
