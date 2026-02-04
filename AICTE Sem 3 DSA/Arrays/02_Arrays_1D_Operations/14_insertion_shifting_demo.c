/*
 * Program: 14. Insertion with step-by-step shifting output
 * Language: C
 * Description: Visualizes how elements shift to the right during insertion.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2; // Inserting at index 2 (value 30 currently)
    int value = 99;
    int i;

    printf("Original Array: ");
    printArray(arr, n);

    printf("\nInserting %d at index %d...\n", value, pos);
    
    // Shifting loop with visualization
    for(i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i]; // Move element one step right
        printf("Shifted %d to index %d: ", arr[i], i + 1);
        printArray(arr, n + 1); // Print intermediate state
    }

    arr[pos] = value; // Insert value
    n++; // Increment size

    printf("\nFinal Array: ");
    printArray(arr, n);

    return 0;
}

// Time Complexity: O(N) - Shifting elements.
// Space Complexity: O(1).
