#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    pid_t child = fork(); // creates child process

    if(child == 0) { // in the child process prints its PID
        printf("child PID %d\n", getpid());
        return 0;
    }
    else{ // in the parent process prints its PID
        printf("parent PID %d\n",getpid());
    }
    return 0;
}