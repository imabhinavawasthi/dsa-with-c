// File: 4_min_heap_array.c
// Purpose: Demonstrate Array Representation of Min Heap
// Author: Abhinav Awasthi

#include <stdio.h>

/*
 * Array Representation:
 * The array allows us to traverse the tree without pointers.
 * For node at index 'i':
 * - Parent: (i - 1) / 2
 * - Left Child: 2 * i + 1
 * - Right Child: 2 * i + 2
 */

void printNodeDetails(int arr[], int size, int i) {
    if (i >= size) return;

    printf("Node Index: %d, Value: %d\n", i, arr[i]);
    
    int p = (i - 1) / 2;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (i != 0) // Root has no parent
        printf(" -> Parent Index: %d, Value: %d\n", p, arr[p]);
    else
        printf(" -> Root Node (No Parent)\n");

    if (l < size)
        printf(" -> Left Child Index: %d, Value: %d\n", l, arr[l]);
    else
        printf(" -> No Left Child\n");

    if (r < size)
        printf(" -> Right Child Index: %d, Value: %d\n", r, arr[r]);
    else
        printf(" -> No Right Child\n");

    printf("\n");
}

int main() {
    // A valid Min Heap Array
    int heap[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;

    printf("Min Heap Array: 10 20 30 40 50 60 70\n");
    printf("--------------------------------------\n");

    // Display details for each node
    for (int i = 0; i < size; i++) {
        printNodeDetails(heap, size, i);
    }

    return 0;
}

// Time Complexity: O(1) for formula calculation
// Space Complexity: O(1)
