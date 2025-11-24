#include <stdio.h>

int AND(int bit1, int bit2){
    int bit3;

    if (bit1 & bit2){
        bit3 = 1;
    }

    else{
        bit3 = 0;
    }

    return bit3;

}

int OR(int bit1, int bit2){
    int bit3;

    if (bit1 | bit2){
        bit3 = 1;
    }

    else{
        bit3 = 0;
    }

    return bit3;
}

int XOR(int bit1, int bit2){
    int bit3;

    if (bit1 ^ bit2){
        bit3 = 1;
    }
    else {
        bit3 = 0;
    }

    return bit3;

}

int main(){
    char operator;
    int  nibble1[4];
    int  nibble2[4];
    int  nibble3[4];

    printf("Enter nibble operator nibble\n");
    scanf("%d %d %d %d %c %d %d %d %d", &nibble1[0], &nibble1[1], &nibble1[2], &nibble1[3], &operator, &nibble2[0], &nibble2[1], &nibble2[2], &nibble2[3]);



    for (int i = 0; i < 4; i++){
        if (((nibble1[i] == 1) || (nibble1[i] == 0)) && ((nibble2[i] == 1) || (nibble2[i] == 0))){
            printf("testing: %d is binary ✓\n", i+1);
        }
        else{
            printf("testing: %d is not binary X\n", i+1);
            return 1;
        }

    }

    switch (operator) {

        case '&':
            for (int i = 0; i < 4; i++){
                nibble3[i] = AND(nibble1[i], nibble2[i]);
                
            }

            break;

        case '|':
            for (int i = 0; i < 4; i++){
                nibble3[i] = OR(nibble1[i], nibble2[i]);
                
            }

            break;

        case '^':
            for (int i = 0; i < 4; i++){
                nibble3[i] = XOR(nibble1[i], nibble2[i]);
                
            }

            break;

        default:
            printf("%c it not an operator\n", operator);
            return 1;

    }

    printf("nibble = %d %d %d %d\n", nibble3[0], nibble3[1], nibble3[2], nibble3[3]);

    return 0;


}
