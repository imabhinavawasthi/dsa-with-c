/*
 * Program: 19. Matrix subtraction
 * Language: C
 * Description: Subtracts elements of second matrix from first matrix.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int mat1[2][2] = {
        {10, 20},
        {30, 40}
    };
    int mat2[2][2] = {
        {5, 5},
        {10, 10}
    };
    int diff[2][2];
    int i, j;

    printf("Matrix 1:\n");
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) printf("%d ", mat1[i][j]);
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) printf("%d ", mat2[i][j]);
        printf("\n");
    }

    // Subtraction Logic
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    printf("\nDifference Matrix:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(R * C).
