#include <stdio.h>

int swap(int *a, int *b){
   int c = *a; // c is temporary variable to store a
   *a = *b;
   *b = c;
}

int main(){

   int a = 10;
   int b = 20;
   printf("before swap a:%d, b:%d\n", a,b);
   int c = swap(&a, &b);
   printf("after swap a:%d, b:%d\n", a,b);

    return 0;
}


// swap function takes two pointers as arguments.
// It swaps the values of the integers that *a and *b point to.
// A temporary variable temp is used to hold the value of *a during the swap.

// Two integers x and y are initialized with values 10 and 20.
// Before calling swap(), the values of x and y are printed.
// swap(&x, &y) passes the addresses of x and y to the swap() function, allowing it to modify the original values.
// After the swap, the new values of x and y are printed.


