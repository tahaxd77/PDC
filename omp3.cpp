#include <omp.h>
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
    #pragma omp parallel for
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
    double start_time, end_time;
    initializeMatrix(A);
    initializeMatrix(B);
    start_time = omp_get_wtime();
    multiplyMatrix(A,B,result);
    end_time = omp_get_wtime();
    printf("Time: %f\n",end_time-start_time);
    printMatrix(result);
    return 0;    
    
}

