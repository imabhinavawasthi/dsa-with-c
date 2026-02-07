/**
 * File: merge_sort.cpp
 * Algorithm: Merge Sort
 * 
 * Idea:
 * Divide the array into two halves.
 * Recursively sort each half.
 * Merge the two sorted halves into a single sorted array.
 * 
 * Recurrence Relation:
 * T(n) = 2T(n/2) + O(n)
 */

#include <iostream>
using namespace std;

// Function to merge two subarrays
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    // In strict ANSI C++, VLA (Variable Length Arrays) are not supported,
    // but in GCC/C++ widely used for competitive programming/exams it is allowed.
    // For standard compliance, dynamic allocation is safer, but exams often accept this.
    // To be safe and simple for exams, we use fixed size or dynamic new.
    // We will use new to be correct in C++.
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Free memory
    delete[] L;
    delete[] R;
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: " << endl;
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: " << endl;
    printArray(arr, n);

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n log n), O(n log n), O(n log n)
// Space Complexity: O(n)
