#include <stdio.h>
#include <stdlib.h>
#define N 10

void initializeMatrix(int matrix [N][N]){
    for (int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            matrix[i][j] = rand()%10;
        }
    }
}

void printMatrix(int matrix [N][N]){
    for (int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int A[N][N],int B[N][N],int result[N][N]){
    for (int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            result[i][j] = 0;
            for (int k=0;k<N;k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int A[N][N],B[N][N],result[N][N];
    initializeMatrix(A);
    initializeMatrix(B);
    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);
    multiplyMatrix(A,B,result);
    printf("Result:\n");
    printMatrix(result);
    return 0;    
    
}

