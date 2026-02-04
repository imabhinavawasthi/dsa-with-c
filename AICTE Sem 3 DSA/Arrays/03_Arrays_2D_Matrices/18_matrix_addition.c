/*
 * Program: 18. Matrix addition
 * Language: C
 * Description: Adds two matrices cell by cell.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int sum[3][3];
    int i, j;

    printf("Matrix 1:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", mat1[i][j]);
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", mat2[i][j]);
        printf("\n");
    }

    // Addition Logic
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("\nSum Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(R * C) for result matrix.
