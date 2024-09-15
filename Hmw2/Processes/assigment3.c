#include <stdio.h>
#include <stdlib.h>

void exit1() {
    printf("exit1 called\n");
}

void exit2() {
    printf("exit2 called\n");
}

int main()
{
    atexit(exit2);
    atexit(exit1);

    return 0;
}

//atexit function is useful on resource cleanup, it can close open files to free other system resources.
//It can be used for logging and deep reporting as well, tracking execution time or storing application state
//it ensures that programm executed. 