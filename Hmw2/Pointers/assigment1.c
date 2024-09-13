#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    int x = 21;

    int* ptr_x = &x;
    printf("address using variable %p\n", &x);
    printf("adress using pointer %p\n", ptr_x);

    *ptr_x = 22;
    printf("address using variable %d\n", x);
    return 0;
}

// int num = 10 declares and initializes an variable.
// int *ptr = &num declares a pointer and assigns it the address of num.
// The addresses of num are printed using both the variable &num and the pointer ptr.
// *ptr = 20; modifies the value of num via the pointer.

