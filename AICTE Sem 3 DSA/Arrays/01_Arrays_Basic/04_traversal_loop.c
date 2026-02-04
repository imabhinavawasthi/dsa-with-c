/*
 * Program: 4. Traverse an array using a loop
 * Language: C
 * Description: Demonstrates how to iterate through all elements of an array.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5; // Size of the array
    int i;

    printf("Traversing array elements:\n");

    // Standard for loop traversal
    for (i = 0; i < n; i++) {
        // Access each element using index i
        printf("Element at index %d is %d\n", i, arr[i]);
    }

    return 0;
}

// Time Complexity: O(N) since we visit every element once.
// Space Complexity: O(1) auxiliary space (ignoring array storage).
