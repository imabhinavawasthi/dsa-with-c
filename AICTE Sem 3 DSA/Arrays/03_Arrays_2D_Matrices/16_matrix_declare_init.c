/*
 * Program: 16. Declare and initialize 2D array
 * Language: C
 * Description: Demonstrates how to create a 2D array (matrix) and assign values.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    // 1. Declare and Initialize a 2x3 matrix (2 rows, 3 columns)
    int matrix[2][3] = {
        {10, 20, 30}, // Row 0
        {40, 50, 60}  // Row 1
    };

    printf("2D Array Elements:\n");

    // 2. Access elements manually
    printf("Element at [0][0]: %d\n", matrix[0][0]);
    printf("Element at [0][1]: %d\n", matrix[0][1]);
    printf("Element at [0][2]: %d\n", matrix[0][2]);
    printf("Element at [1][0]: %d\n", matrix[1][0]);
    printf("Element at [1][1]: %d\n", matrix[1][1]);
    printf("Element at [1][2]: %d\n", matrix[1][2]);

    return 0;
}

// Time Complexity: O(1) for direct access.
// Space Complexity: O(R * C) where R is rows, C is cols.
