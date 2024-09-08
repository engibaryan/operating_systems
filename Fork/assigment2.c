#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main() {
    pid_t child1, child2;

    child1 = fork();

    if(child1 < 0) {
        //fork failed
        exit(1);
    }
    else if(child1 == 0) {
        //child process
         execl("/bin/ls", "ls", NULL);
         exit(1);
    } 
    child2 = fork();

    if(child2 < 0) {
        perror("Fork failed");
    }
    else if(child2 == 0) {
        execl("/bin/date", "date", NULL);
        exit(1);
    }
        //parent process
        printf("Parent process done\n");
   
    
 
    return 0;
}