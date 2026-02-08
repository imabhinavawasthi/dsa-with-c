// File: 9_heap_sort.c
// Purpose: Implement Heap Sort (O(N log N) In-Place Sort)
// Author: Abhinav Awasthi

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/*
 * Heapify Down for Max Heap:
 * Used to maintain Max Heap property for Heap Sort.
 */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/*
 * Heap Sort Logic:
 * 1. Build a Max Heap from the array. (O(N))
 * 2. Repeatedly swap root (Max) with last element.
 * 3. Reduce heap size by 1.
 * 4. Heapify root.
 * 5. Repeat until size is 1.
 * 
 * Result: The array will be sorted in Ascending Order.
 */
void heapSort(int arr[], int n) {
    // 1. Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 2. Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end (Swap max to end)
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted Array:   ");
    printArray(arr, n);

    // Explanation:
    // This is O(N log N) because we extract N elements, and each extraction
    // takes O(log N) to heapify.
    // Space Complexity is O(1) because it is in-place.

    return 0;
}

// Time Complexity: O(N log N)
// Space Complexity: O(1)
