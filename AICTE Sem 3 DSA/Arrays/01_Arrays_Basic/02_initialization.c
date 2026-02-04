/*
 * Program: 2. Initialize an array at declaration
 * Language: C
 * Description: Shows how to initialize an array with values effectively in one line.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    // Method 1: Initialize with specific size and values
    int arr1[5] = {10, 20, 30, 40, 50};

    // Method 2: Initialize without specifying size (Compiler determines size)
    int arr2[] = {5, 15, 25};

    // Method 3: Partial initialization (Remaining elements become 0)
    int arr3[5] = {100, 200}; // Index 2, 3, 4 will be 0

    // Printing elements from arr1 (using a simple manual print for clarity)
    printf("arr1 elements:\n");
    printf("%d %d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4]);

    // Printing elements from arr3 to show zero-initialization
    printf("\narr3 elements (showing partial initialization):\n");
    printf("%d %d %d %d %d\n", arr3[0], arr3[1], arr3[2], arr3[3], arr3[4]);

    return 0;
}

// Time Complexity: O(N) for initialization (handled by compiler/runtime).
// Space Complexity: O(N) for storing the elements.
