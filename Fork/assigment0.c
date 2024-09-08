#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    fork();
    fork();
    fork();
    //total number of processes is 2 raised to n, where n is the number of fork() system calls.
    printf("Hi! \n PID=%d\n", getpid());
    return 0;
}