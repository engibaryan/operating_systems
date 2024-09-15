#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    // Create a child process
    pid_t child = fork();


    if (child == 0) {
        // In the child process
        printf("Child Process: My PID is %d, Parent PID is %d\n", getpid(), getppid());
        exit(0);  // Child process terminates
    } else {
       // In the parent process
        printf("Parent Process: My PID is %d, Child PID is %d\n", getpid(), child);

        // Wait for the child to terminate and collect its exit status
        int status;
        wait(&status);

        // Check if the child exited normally
        if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
        }
    }
   
    return 0;
}
//A zombie process occurs when a child process terminates, 
//but its parent process has not yet collected its exit status. 
//The operating system keeps the child process's entry in the process table (with a "zombie" status) 
//so that the parent can later retrieve the child's termination status using wait() or waitpid().

//wait() makes the parent process pause until one of its child processes terminates. 
//When the child process terminates, wait() collects its exit status, 
//which allows the operating system to remove the child’s process entry from the process table. 
//This prevents the child from becoming a zombie.

//Similar to wait(), but waitpid() allows the parent to wait for a specific child process 
//(by passing the child’s PID). 
//It also allows for more control over how the parent waits for child processes, 
//such as non-blocking or waiting for a child to stop (not terminate).