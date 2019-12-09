#include <iostream>
#include <unistd.h>
#include <string.h>


using namespace std;

int main() {
    
    //parent to child pipe
    int pp2c[2];
    //child to parent pipe
    int pc2p[2];

    //vars from sums
    int childSum = 0;
    int parentSum = 0;

    //amount of terms
    int terms = 10;

    //amount of bytes
    int bytes = 100;

    //creates pipes and places 2 file descriptor into each pipe for read and write
    //returns 0 if it successful
    pipe(pp2c); 
    pipe(pc2p);

    //fork() to create the processes
    //create the process and check it is successful
    switch (fork()){
        //this will be the child process
        case 0:


            //calculate the partial sum of 1-5
            for(int i =1; i <= terms / 2; i++ )
            {
                childSum += i;

            }

            //output the calculated sum
            cout << "Child calculated sum: " << childSum << endl;
           


            //write the result to the parent pipe
            write(pc2p[1], &childSum, sizeof(childSum));
            close(pc2p[1]); //close the write 

            //break out of switch statement
            break;
        case -1: 
            cout << "failure of process" << endl;
            break;
        //parent process
        default: 

            //var to recieve sum form child
            int recievedSum;

             
            //read from child pipe
            read(pc2p[0], &recievedSum, sizeof(recievedSum));
            close(pc2p[0]); 

            //calculate the partial sum of 6-10
            for(int i = (terms/2) + 1; i <= 10; i++ )
            {
                parentSum += i;

            }

            //output the calculated sum
            cout << "Parent calculated sum: " << parentSum << endl;
          

            //add the 2 sums together
            parentSum += recievedSum;

            //output the total sum
            cout <<  "The total sum is:  " << parentSum << endl;
            //break out of switch statement
            break;
    }


    return 0;

}
