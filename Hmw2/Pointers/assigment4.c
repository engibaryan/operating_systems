#include <stdio.h>
int main() {
    int x = 45;
    int *ptr_x = &x; 

    int **double_ptr = &ptr_x;

    printf("Value of x using pointer %d\n", *ptr_x);
    printf("Value of x using double pointer %d\n", **double_ptr);

    return 0;
}

// int x = 45: Declares an integer variable num and initializes it with the value 100.
// int *ptr_x = &x: Declares a pointer ptr_x that stores the address of the integer x.
// int **double_ptr = &ptr_x: Declares a double-pointer double_ptr that stores the address of the pointer ptr_x.
// *ptr_x: Dereferences ptr to access the value of x.
// **double_ptr: Dereferences double_ptr twice to get the value of x.

