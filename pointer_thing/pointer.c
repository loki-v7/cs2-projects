
#include <stdio.h>


void swap(int *ptr_1, int *ptr_2) {
   /*Write a function that will take two pointers x and y and exchange their values
    *using pointers. */
  int temp = *ptr_1;
  *ptr_1 = *ptr_2;
  *ptr_2 = temp;

}

void zero(int *ptr_List) {
   /*Write a function that will take a pointer to an array and loop through, setting
    *all values to zero.*/

  for (int i = 0; i < 5; i++)
    *(ptr_List + i) = 0;

}


int main(){
   int a = 5;
   int b = 7;
   int nums[5] = {1, 4, 7, 11, 19};


   /* We need a line of code that calls the swap function for a and b.*/


   /* We need a line of code that calls the zero function for the array nums.*/
  
   printf("a = %d\n", a);
   printf("b = %d\n", b);

   for (int i = 0; i < 5; i++) {
       printf("%d\n", nums[i]);
   }

   swap(&a, &b);

   zero(nums);


   printf("a = %d\n", a);
   printf("b = %d\n", b);
   for (int i = 0; i < 5; i++) {
       printf("%d\n", nums[i]);
   }

   /*Write a series of print statements that will print the same informaiton as above
    *but using pointer references that you define instead of a and b.*/
  
  
   return 0;
}

