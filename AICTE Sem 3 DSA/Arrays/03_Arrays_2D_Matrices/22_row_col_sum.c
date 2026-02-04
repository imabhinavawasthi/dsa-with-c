/*
 * Program: 22. Row-wise and column-wise sum
 * Language: C
 * Description: Calculates the sum of each row and each column separately.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int i, j, sum;

    printf("Original Matrix:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Row-wise Sum
    printf("\nRow-wise Sum:\n");
    for(i = 0; i < 3; i++) {
        sum = 0;
        for(j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
        printf("Row %d Sum = %d\n", i, sum);
    }

    // Column-wise Sum
    printf("\nColumn-wise Sum:\n");
    for(j = 0; j < 3; j++) { // Loop columns first
        sum = 0;
        for(i = 0; i < 3; i++) { // Then loop rows
            sum += matrix[i][j];
        }
        printf("Column %d Sum = %d\n", j, sum);
    }

    return 0;
}

// Time Complexity: O(R * C) for each pass.
// Space Complexity: O(1).
