#include <stdio.h>



int main(){

    int randomArray[] = {16, 18, 17, 15};
    int temp;
    int size = sizeof(randomArray) / sizeof(randomArray[0]);
    

    for (int i = 0; i < size; i++){

        if (randomArray[i] >= randomArray[i+1]){;}
            
        else {
            printf("before: %d, %d\n", randomArray[i], randomArray[i+1]);
            temp = randomArray[i+1];
            randomArray[i+1] = randomArray[i];
            randomArray[i] = temp;
            printf("after: %d, %d\n", randomArray[i], randomArray[i+1]);
        }
    }

    for (int i = size-1; i >= 0; i--) {
        printf("%d ", randomArray[i]);
    }
    printf("\n");



}
