/*
 * Program: 21. Sum of all elements
 * Language: C
 * Description: Calculates the sum of all elements in a matrix.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int matrix[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int sum = 0;
    int i, j;

    printf("Matrix:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Calculating Sum
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }

    printf("\nTotal Sum of all elements: %d\n", sum);

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(1).
