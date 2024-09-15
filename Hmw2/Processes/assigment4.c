#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main() {
    pid_t child = fork(); // creates child process
    int status;

    if(child == 0) { // in the child process prints its PID
        printf("child1 is running, exit code 10\n");
        exit(10);
    }
   
    pid_t child2 = fork();

    if(child2 == 0) {
        printf("child2 is running, exit code 20\n");
        exit(20);
    }

    

    pid_t waitPID1 = waitpid(child, &status,0);
    if(waitPID1 = child)
    {
        if(WIFEXITED(status)) { //Checks if the child process terminated normally (i.e., via exit()).
            printf("Parent: First Child PID: %d exited with status %d\n", child, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Parent: First Child PID: %d was terminated by signal %d\n", child, WTERMSIG(status));
        }
    }
    pid_t waitPID2 = waitpid(child2, &status,0);
    if(waitPID2 == child2)
    {
        if(WIFEXITED(status)){ //Checks if the child process terminated normally (i.e., via exit()).
            printf("Parent: Second Child PID: %d exited with status %d\n", child2, WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)) {
            printf("Parent: Second Child PID: %d was terminated by signal %d\n", child2, WTERMSIG(status));
        }
    }
    return 0;
}

// Each child prints its PID and then exits with a unique exit code (10 for the first child, 20 for the second child) using exit().
// WEXITSTATUS(status): Retrieves the exit status of the child process (the code passed to exit()).
// WIFSIGNALED(status): Checks if the child process was terminated by a signal.
// WTERMSIG(status): Retrieves the signal number that caused the termination, if applicable.