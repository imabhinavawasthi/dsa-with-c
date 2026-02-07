/**
 * File: bubble_sort.cpp
 * Algorithm: Bubble Sort
 * 
 * Idea:
 * Repeatedly swap adjacent elements if they are in the wrong order.
 * In each pass, the largest element "bubbles up" to its correct position at the end.
 * Optimized with a 'swapped' flag to stop early if the array is already sorted.
 */

#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to check if any swap happens
        
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: " << endl;
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted Array: " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n), O(n^2), O(n^2)
// Space Complexity: O(1)
