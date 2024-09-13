#include <stdio.h>

int swap(int *a, int *b){
   int c = *a;
   *a = *b;
   *b = c;
}

int main(){

   int a = 10;
   int b = 20;
   printf("before swap a:%d, b:%d\n", a,b);
   int c = swap(&a, &b);
   printf("after swap a:%d, b:%d\n", a,b);
}

