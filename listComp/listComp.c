#include <stdio.h>
#include <stdlib.h>


int listSize1, listSize2, listSize3 = 0;

int* compareList(int *listA, int* listB){
  int listcounter = 0;

  for (int i = 0; i < listSize1; i++) {
    for (int j = 0; j < listSize2; j++) {
      // i forgot how to code here
      if (listA[i] == listB[j]) {
        // need to make a list of the matches and get the size of it
        listSize3 += 1;
      }
    }
  }

  int* listC = malloc(sizeof(int)*listSize3);

  for (int i = 0; i <= listSize1; i++) {
    for (int j = 0; j <= listSize2; j++) {
      // i forgot how to code here too

      if (listA[i] == listB[j]) {
        listC[listcounter] = listB[j];
        listcounter += 1;
      }
    }
  }
   

  return listC;
}

int main(){

  printf("Enter size of list 1: ");
  scanf("%d", &listSize1);

  printf("Enter size of list 2: ");
  scanf("%d", &listSize2);

  int *list1 = malloc(sizeof(int)*listSize1);

  int *list2 = malloc(sizeof(int)*listSize2);
  

  printf("\n_____List 1_____\n");

  for (int i = 0; i < listSize1; i++) {
    printf("Enter num %d: ", i+1);
    scanf("%d", &list1[i]);
  }
  
  printf("\n_____List 2_____\n");

  for (int i = 0; i < listSize2; i++) {
    printf("Enter num %d: ", i+1);
    scanf("%d", &list2[i]);
  }

  int* list3 = compareList(list1, list2);

  for (int i = 0; i < listSize3; i++) {
    printf("%d ", list3[i]);
  }
  printf("\n");


  return 0;
}
