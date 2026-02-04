/*
 * Program: 12. Reverse an array
 * Language: C
 * Description: Reverses the array elements in-place using two pointers.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int start = 0, end = n - 1;
    int temp, i;

    // Printing original array
    printf("Original Array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Reversing Logic (Swap elements at start and end)
    while (start < end) {
        // Swap
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers
        start++;
        end--;
    }

    // Printing reversed array
    printf("Reversed Array: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// Time Complexity: O(N) - We visit each element once (N/2 swaps).
// Space Complexity: O(1) - In-place reversal (no new array created).
