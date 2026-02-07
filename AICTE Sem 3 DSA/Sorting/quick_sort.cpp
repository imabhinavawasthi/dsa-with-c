/**
 * File: quick_sort.cpp
 * Algorithm: Quick Sort
 * 
 * Idea:
 * Select a 'pivot' element from the array.
 * Partition the array such that:
 * - All elements smaller than pivot are on the left.
 * - All elements greater than pivot are on the right.
 * Recursively sort the sub-arrays.
 * 
 * Worst Case Scenario:
 * Occurs when the array is already sorted or reverse sorted (if last element is pivot).
 * T(n) = O(n^2)
 */

#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
// Takes last element as pivot
// Returns the index of pivot after placing it in correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: " << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n log n), O(n log n), O(n^2)
// Space Complexity: O(log n) (for recursion stack)
