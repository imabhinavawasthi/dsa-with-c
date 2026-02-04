/*
 * Program: 11. Find maximum and minimum element
 * Language: C
 * Description: Finds the largest and smallest numbers in an array efficiently.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[] = {15, 30, 10, 50, 25, 5, 45};
    int n = 7;
    int max, min, i;

    printf("Array: 15, 30, 10, 50, 25, 5, 45\n");

    // Initialize max and min with the first element
    max = arr[0];
    min = arr[0];

    // Traverse the rest of the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if current element is larger
        }
        
        if (arr[i] < min) {
            min = arr[i]; // Update min if current element is smaller
        }
    }

    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);

    return 0;
}

// Time Complexity: O(N) - We traverse the array once.
// Space Complexity: O(1).
