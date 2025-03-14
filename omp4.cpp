#include <omp.h>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 4

void initializeMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrix(int A[N][N], int B[N][N], int result[N][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
                cout << "Thread " << omp_get_thread_num() 
                     << ": result[" << i << "][" << j 
                     << "] += A[" << i << "][" << k 
                     << "] * B[" << k << "][" << j 
                     << "] = " << result[i][j] << endl;
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], result[N][N];
    double start_time, end_time;
    
    initializeMatrix(A);
    initializeMatrix(B);
    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);
    
    start_time = omp_get_wtime();
    multiplyMatrix(A,B,result);
    end_time = omp_get_wtime();
    
    cout << "Time: " << end_time - start_time << endl;
    printMatrix(result);
    
    return 0;
}