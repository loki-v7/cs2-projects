#include <stdio.h>


int main(){

    int numList[] = {52, 18, 3, 99, 15, 18, 18, 18, 22, 91, 35, 80, 77, 64, 101, 22, 55, 88}; 
    int temp = numList[0]; 
    int size = sizeof(numList) / sizeof(numList[0]); // Calculate array size


    for (int i = 0; i < size; i++){

        if (temp >= numList[i]){
            ;
        }

        else {
            temp = numList[i];
        }
    }
        
    printf("%d\n", temp);

    return 0;

}
