// File: 8_heapify_build.c
// Purpose: Build Heap from Arbitrary Array (Heapify Method)
// Author: Abhinav Awasthi

#include <stdio.h>

/*
 * Build Heap Logic:
 * Instead of inserting elements one by one (O(N log N)),
 * we treat the array as a complete binary tree and run heapifyDown
 * starting from the LAST NON-LEAF NODE up to the root.
 * 
 * Last Non-Leaf Node Index = (n / 2) - 1
 * Total Time Complexity: O(N) (Mathematical property of converging series)
 */

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // We are building a MAX HEAP here as standard example, 
    // but same logic applies to Min Heap (just change condition).
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    // Start from last non-leaf node and go up to root
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    buildHeap(arr, n);

    printf("Built Max Heap: ");
    printArray(arr, n);

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(log N)
