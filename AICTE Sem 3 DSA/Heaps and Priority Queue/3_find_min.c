// File: 3_find_min.c
// Purpose: Demonstrate findMin operation in Min Heap
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/*
 * Find Min Operation:
 * In a Min Heap, the minimum element is ALWAYS at the root (index 0).
 * Accessing this is O(1) time complexity.
 */

int heap[] = {10, 20, 30, 40, 50}; // Example of Min Heap array
int size = 5;

int findMin() {
    if (size == 0) {
        printf("Heap is Empty\n");
        return -1;
    }
    // Min element is at index 0
    return heap[0];
}

int main() {
    printf("Current Heap Array: 10 20 30 40 50\n");
    
    int minVal = findMin();
    printf("Minimum Element in Heap: %d\n", minVal);
    printf("Time Complexity to find Min: O(1)\n");

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
