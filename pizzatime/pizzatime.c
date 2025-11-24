#include <stdio.h>



int main(){
    int size;
    int toppings;
    char fee_check;
    float fee;

    printf("Buona giornata to Leo's Fantastic Pizzeria \n");
    printf("What size of pizza? \n1:Small 2:Medium 3:Large 4:Xtra Large: \n");
    scanf("%d", &size);

    printf("How many toppings?: \n");
    scanf("%d", &toppings);
    
    printf("Delivery?\n[y or n]: \n");
    getchar();
    scanf(" %c", &fee_check);

    if (fee_check == 'y'){
        fee = 5.00;
    }
    else {
        fee = 0.00;
    }


    if (size == 1){
        float toppings_cost = toppings * 0.95;
        float total = 8.25 + toppings_cost + fee;
        float total_tax = total * 1.032;
        printf("your total is %.2f\n", total_tax);
    }

    else if (size == 2){
        float toppings_cost = toppings * 1.25;
        float total = 10.25 + toppings_cost + fee;
        float total_tax = total * 1.032;
        printf("your total is %.2f\n", total_tax);
    }

    else if (size == 3){
        float toppings_cost = toppings * 1.75;
        float total = 12.25 + toppings_cost + fee;
        float total_tax = total * 1.032;
        printf("your total is %.2f\n", total_tax);
    }

    else if (size == 4){
        float toppings_cost = toppings * 2.05;
        float total = 14.25 + toppings_cost + fee;
        float total_tax = total * 1.032;
        printf("your total is %.2f\n", total_tax);
    }
    printf("\n");
    return 0;

}
