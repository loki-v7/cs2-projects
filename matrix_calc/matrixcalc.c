#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int** matrix;
    int   rows;
    int   cols;
};


int** make_Matrix(int rows, int cols){

    int** matrix = (int**)malloc(rows * sizeof(int*));

    if (matrix == NULL){
        return NULL;
    }


    for (int i = 0; i < rows; i++){
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL){
            for (int j = 0; j < i; j++){
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = 0;
        }
    }
    return  matrix; 

}

void free_Matrix(int** matrix, int rows){
    if (matrix == NULL){
        return;
    }

    for (int i = 0; i < rows; i++){
        free(matrix[i]);
    }

    free(matrix);
}


int** fill_Matrix(int rows, int cols, int** matrix){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("\nEnter value for row %d, col %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }

    }

    return matrix;
}



int** add_Matrices(int** A, int** B, int aRows, int aCols, int bRows, int bCols){
    int** AB = make_Matrix(aRows, aCols);

    if (AB == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }



    if (aRows != bRows ||  aCols != bCols){
        printf("Doesnt match");
        exit(EXIT_FAILURE);
    }

    else{
        for (int i = 0; i < aRows; i++){
            for (int j = 0; j < aCols; j++){
                AB[i][j] = A[i][j] + B[i][j];
            }
        }
    }

    return AB;

}

struct matrix multiply_Matrices(int** A, int** B, int aRows, int aCols, int bRows, int bCols){
    int** AB = make_Matrix(aRows, bCols);

    struct matrix abMatrix;


    if (AB == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    if (bRows != aCols){
        printf("doesnt multiply");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < aRows; i++){
        for(int j = 0; j < bCols; j++){
            AB[i][j] = 0;

            for (int k = 0; k < bRows; k++){
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    abMatrix.matrix = AB;
    abMatrix.rows = aRows;
    abMatrix.cols = bCols;

    return abMatrix;


}


int main(){
    int aRows, aCols, bRows, bCols; 
    int matrix_Operator;

    //Needs a cool title in ascii

    printf("\nEnter num of rows for matrix A: ");
    scanf("%d", &aRows);

    printf("\nEnter num of cols for matrix A: ");
    scanf("%d", &aCols);

    printf("\nEnter num of rows for matrix B: ");
    scanf("%d", &bRows);

    printf("\nEnter num of cols for matrix B: ");
    scanf("%d", &bCols);

    int** aMatrix = make_Matrix(aRows, aCols);

    int** bMatrix = make_Matrix(bRows, bCols);

    if (aMatrix == NULL || bMatrix == NULL){ // I don't know if this will work it might just break
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\n_______Matrix A_______");
    aMatrix = fill_Matrix(aRows, aCols, aMatrix);

    printf("\n_______Matrix B_______");
    bMatrix = fill_Matrix(bRows, bCols, bMatrix);


    for (int i = 0; i < aRows; i++){
        for (int j = 0; j < aCols; j++){
            printf("\nmatrix A: row %d column %d = %d", i + 1, j + 1, aMatrix[i][j]);
        }

    }

    for (int i = 0; i < bRows; i++){
        for (int j = 0; j < bCols; j++){
            printf("\nmatrix B: row %d column %d = %d", i + 1, j + 1, bMatrix[i][j]);
        }
    }
    printf("\n");

    printf("(1) A+B\n(2) AB\n(3) BA\n");
    scanf("%d", &matrix_Operator);

    if (matrix_Operator == 1){
        int** cMatrix;
        cMatrix = add_Matrices(aMatrix, bMatrix, aRows, aCols, bRows, bCols);
        for (int i = 0; i < aRows; i++){
            for (int j = 0; j < bCols; j++){
            printf("\nmatrix C: row %d column %d = %d", i + 1, j + 1, cMatrix[i][j]);
            }
        }
        free_Matrix(cMatrix, aRows);
        free_Matrix(aMatrix, aRows);
        free_Matrix(bMatrix, bRows);
    }

    else if (matrix_Operator == 2){
        struct matrix cMatrix; 

        cMatrix = multiply_Matrices(aMatrix, bMatrix, aRows, aCols, bRows, bCols);
        for (int i = 0; i < cMatrix.rows; i++){
            for (int j = 0; j < cMatrix.cols; j++){
            printf("\nmatrix C: row %d column %d = %d", i + 1, j + 1, cMatrix.matrix[i][j]);
            }
        }

    free_Matrix(cMatrix.matrix, cMatrix.rows);
    free_Matrix(aMatrix, aRows);
    free_Matrix(bMatrix, bRows);
    }

    else if (matrix_Operator == 3){

        struct matrix cMatrix; 

        cMatrix = multiply_Matrices(bMatrix, aMatrix, bRows, bCols, aRows, aCols);
        for (int i = 0; i < cMatrix.rows; i++){
            for (int j = 0; j < cMatrix.cols; j++){
            printf("\nmatrix C: row %d column %d = %d", i + 1, j + 1, cMatrix.matrix[i][j]);
            }
        }
        free_Matrix(cMatrix.matrix, cMatrix.rows);
        free_Matrix(aMatrix, aRows);
        free_Matrix(bMatrix, bRows);
    }




    else{
        printf("not and option");
        free_Matrix(aMatrix, aRows);
        free_Matrix(bMatrix, bRows);

        return 1;
    }
    


    return 0;


}
