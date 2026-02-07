/**
 * File: selection_sort.cpp
 * Algorithm: Selection Sort
 * 
 * Idea:
 * Repeatedly find the minimum element from the unsorted part
 * and put it at the beginning.
 * The array is divided into two parts: sorted and unsorted.
 */

#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: " << endl;
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted Array: " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n^2), O(n^2), O(n^2)
// Space Complexity: O(1)
