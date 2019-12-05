#include <iostream>
#include <unistd.h>
#include<string>


using namespace std;

int main() {
    
    //parent to child pipe
    int pp2c[2];
    //child to parent fork
    int pc2p[2];

    //creates pipes and places 2 file descriptor into each pipe for read and write
    //returns 0 if it successful
    pipe(pp2c); 
    pipe(pc2p);

    //fork() to create the processes
    //create the process and check it is successful
    switch (fork()){
        //this will be the child process
        case 0:
            cout << "success" << endl;
            break;
        case -1: 
            cout << "failure" << endl;
            break;
        default: {
            //parent process
        }
    }


    return 0;

}
