/**
 * File: insertion_sort.c
 * Algorithm: Insertion Sort
 * 
 * Idea:
 * Build the sorted array one item at a time.
 * Pick the next element and place it in its correct position in the sorted part.
 * Similar to sorting playing cards in your hand.
 */

#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    // Start from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Place key at its correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted Array: \n");
    printArray(arr, n);

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n), O(n^2), O(n^2)
// Space Complexity: O(1)
