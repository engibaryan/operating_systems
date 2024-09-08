#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int child = fork();

    if(child < 0) {
        //fork failed
        exit(1);
    }
    else if(child == 0) {
        //child process
         execl("/bin/ls", "ls", NULL);
    } else {
        //parent process
        printf("Parent process done\n");
   
    }
 
    return 0;
}