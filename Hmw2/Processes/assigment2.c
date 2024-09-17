#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int main() {

    pid_t child = fork(); // creates child process

    if(child == 0) { // in the child process prints its PID
        printf("child PID %d\n", getpid());
        exit(10);
    }
  

    pid_t child2 = fork();
    
    if(child2 == 0) { // in the child process prints its PID
        printf("child PID %d\n", getpid());
        exit(20);
    }
   

   //parent process

    int status; // to capture exit status
    //waiting for first child to complete
    pid_t wait_pid1 = waitpid(child, &status,0);
    if(WIFEXITED(status)){ // WIFEXITED returns true if child process terminated normally
        printf("Parent Process: Child 1 (PID %d) exited with status %d\n", wait_pid1, WEXITSTATUS(status));
    }

    //waiting for second child to complete
    pid_t wait_pid2 = wait(&status);
    if(WIFEXITED(status)){
        printf("Parent Process: Child 2 (PID %d) exited with status %d\n", wait_pid2, WEXITSTATUS(status));
    }

    return 0;
}