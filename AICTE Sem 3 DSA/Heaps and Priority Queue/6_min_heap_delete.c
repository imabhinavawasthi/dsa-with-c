// File: 6_min_heap_delete.c
// Purpose: Demonstrate Delete Min and Heapify-Down
// Author: Abhinav Awasthi

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/*
 * Heapify Down:
 * 1. Compare node with Left and Right children.
 * 2. Find smallest among Parent, Left, Right.
 * 3. Swap with smallest.
 * 4. Repeat down the tree.
 */
void heapifyDown(int arr[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&arr[index], &arr[smallest]);
        heapifyDown(arr, size, smallest);
    }
}

void deleteMin(int arr[], int *size) {
    if (*size <= 0) return;

    int minVal = arr[0];
    arr[0] = arr[*size - 1]; // Move last to root
    (*size)--;

    heapifyDown(arr, *size, 0); // Fix
    
    printf("Deleted %d. Heap: ", minVal);
    for (int i=0; i<*size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int heap[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;

    printf("Initial Heap: ");
    for (int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n");

    deleteMin(heap, &size); // Removes 10
    deleteMin(heap, &size); // Removes 20
    deleteMin(heap, &size); // Removes 30

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(1) Iterative / O(log N) Recursive
