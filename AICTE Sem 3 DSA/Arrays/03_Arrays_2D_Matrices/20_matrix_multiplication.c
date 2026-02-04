/*
 * Program: 20. Matrix multiplication
 * Language: C
 * Description: Multiplies two matrices. Rows of 1st matrix must match Cols of 2nd.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int matA[2][2] = {{1, 2}, {3, 4}};
    int matB[2][2] = {{5, 6}, {7, 8}};
    int result[2][2] = {{0, 0}, {0, 0}}; // Initialize to 0
    int i, j, k;

    printf("Multiplying 2x2 Matrices...\n");

    // Matrix Multiplication Logic
    // Row of A * Col of B
    for(i = 0; i < 2; i++) { // Rows of A
        for(j = 0; j < 2; j++) { // Cols of B
            for(k = 0; k < 2; k++) { // Common dimension
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    printf("Result Matrix:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(R1 * C2 * C1) -> Typically O(N^3) for square matrices.
// Space Complexity: O(R1 * C2) for result matrix.
