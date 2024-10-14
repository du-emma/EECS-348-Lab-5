/*
Name: Emma Du
KUID: 3134852
Lab Session: Friday at 1pm with Toye
Lab Assignment Number: 05
Program Description: Program takes two provided matrices as input and performs operations (addition, multiplication) or transposes the matrix and prints the result
Collaborators: None
*/

#include <stdio.h>
#define SIZE 5


/*
 * Function to add two matrices
 */
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}


/*
 * Function to multiply two matrices
 */
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize the result matrix to 0
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}


/*
 * Function to transpose a matrix
 */
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}


/*
 * Function to print a matrix
 */
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}


/*
 * Main function ro perform matrix manipulation by calling corresponding functions
 *
 */
int main() {
    // Sample input matrices
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE];  // To store results of matrix operations

    // Matrix Addition
    printf("Matrix Addition (m1 + m2):\n");
    addMatrices(m1, m2, result);
    printMatrix(result);

    // Matrix Multiplication
    printf("\nMatrix Multiplication (m1 * m2):\n");
    multiplyMatrices(m1, m2, result);
    printMatrix(result);

    // Matrix Transpose of m1
    printf("\nTranspose of Matrix m1:\n");
    transposeMatrix(m1, result);
    printMatrix(result);

    return 0;
}