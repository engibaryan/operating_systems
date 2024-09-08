#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main() {
    pid_t child = fork();

    if(child < 0) {
        //fork failed
        exit(1);
    }
    else if(child == 0) {
        //child process
         execl("/bin/echo","echo", "Hello from child", NULL);
    } else {
        //parent process
        wait(NULL);
        printf("Parent process done\n");
   
    }
 
    return 0;
}