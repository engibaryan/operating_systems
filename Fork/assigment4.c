#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main()
{
    pid_t child = fork();

    if (child < 0)
    {
        // fork failed
        exit(1);
    }
    else if (child == 0)
    {
        // child process
        execl("/bin/grep", "grep",
              "standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10",
              "text.txt", NULL);
    }
    else
    {
        // parent process
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}