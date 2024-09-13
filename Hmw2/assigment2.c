#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
   int myArray[] = {12, 4, 23, 94, 1948};

   int *array_ptr = myArray;


   printf("Before modification: \n");
   for (int i = 0; i < 5; i++) 
   {
    printf("%d ", *(array_ptr + i));
   }
   printf("\n");

   for(int i = 0; i < 5; i++)
   {
    *(array_ptr + i) = *(array_ptr + i) + 1+2*i; // arr[i] is same as *(p + i), so arr[i] = arr[i] + 1+2*i
   } 

    printf("after modification: \n");
   for (int i = 0; i < 5; i++) 
   {
    printf("%d ", array_ptr[i]);
   }
   printf("\n");

    return 0;
}

// We declare an integer array myArray with 5 values.
// A pointer array_ptr is used to point to the first element of the array.
// Using pointer arithmetic, we traverse the array and print its elements.
// The array elements are modified by 1+2*i formula, where i goes from 0 to 5
// We print the modified array first using traditional method