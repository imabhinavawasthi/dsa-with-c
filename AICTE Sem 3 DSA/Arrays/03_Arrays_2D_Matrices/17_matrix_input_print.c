/*
 * Program: 17. Input and print matrix
 * Language: C
 * Description: Takes user input for a matrix and prints it in a proper format.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[10][10]; // Max size 10x10

    printf("Enter number of rows (max 10): ");
    scanf("%d", &rows);
    printf("Enter number of columns (max 10): ");
    scanf("%d", &cols);

    // 1. Input Loop
    printf("\nEnter elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 2. Output Loop (Printing in Matrix form)
    printf("\nThe Matrix is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]); // \t for tab spacing
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}

// Time Complexity: O(Rows * Cols) - Iterating through all elements.
// Space Complexity: O(1) auxiliary (assuming fixed max size).
