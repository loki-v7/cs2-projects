#include <stdio.h>


int main(){
  float num = 3.14;
  float *ptr = &num;


  printf("The size of a the pointer is %zu\n", sizeof(ptr));
  return 0;
}

