// File: 1_min_priority_queue.c
// Purpose: Implement Min Priority Queue using Binary Heap (Array Implementation)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/*
 * Priority Queue (Min Heap) Concept:
 * A Complete Binary Tree where every node is SMALLER than its children.
 * Root (index 0) is always the Minimum Element.
 * 
 * Array Formulas (0-based index):
 * Parent = (i - 1) / 2
 * Left Child = 2 * i + 1
 * Right Child = 2 * i + 2
 */

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain Heap Property during insertion (Heapify-Up)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    // Keep swapping with parent if current element is smaller than parent
    while (index > 0 && heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to maintain Heap Property after deletion (Heapify-Down)
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Check if Left child exists and is smaller than current smallest
    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    // Check if Right child exists and is smaller than current smallest
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // If smallest is not root, swap and continue heapifying down
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert Element
void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Queue Overflow\n");
        return;
    }
    // Add to end
    heap[size] = value;
    size++;
    // Use Heapify-Up to fix order
    heapifyUp(size - 1);
    printf("Inserted %d\n", value);
}

// Remove Minimum Element
int extractMin() {
    if (size <= 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int minVal = heap[0];
    // Move last element to root
    heap[0] = heap[size - 1];
    size--;
    // Use Heapify-Down to fix order
    heapifyDown(0);
    return minVal;
}

// Helper to print heap
void printHeap() {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(4);
    insert(9);
    insert(1); // Should become new root
    insert(7);
    insert(5);
    insert(3);

    printHeap(); // Expected: 1 at index 0

    printf("Extracted Min: %d\n", extractMin());
    printHeap(); // Root should be next smallest

    return 0;
}

// Time Complexity: 
//   - Insert: O(log N)
//   - ExtractMin: O(log N)
// Space Complexity: O(N) for array
