/*
 * Program: 6. Find array length using sizeof
 * Language: C
 * Description: Calculates the number of elements in an array using the sizeof operator.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};

    // sizeof(arr) gives total bytes occupied by the array
    // sizeof(arr[0]) gives bytes occupied by one element (e.g., 4 bytes for int)
    
    // Formula: Length = Total Bytes / Bytes per Element
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Total size of array in bytes: %lu\n", sizeof(arr));
    printf("Size of one element (int): %lu\n", sizeof(arr[0]));
    printf("Number of elements in array: %d\n", n);

    return 0;
}

// Time Complexity: O(1) - Computed at compile time.
// Space Complexity: O(1).
