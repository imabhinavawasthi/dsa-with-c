// File: 2_max_priority_queue.c
// Purpose: Implement Max Priority Queue using Binary Heap
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/*
 * Max Heap Property:
 * Parent is always GREATER than or equal to children.
 * Root is the MAXIMUM element.
 */

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up for Max Heap (Parent must be larger)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify Down for Max Heap (Parent must be larger)
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compare with Left Child
    if (left < size && heap[left] > heap[largest])
        largest = left;

    // Compare with Right Child
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Queue Overflow\n");
        return;
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
    printf("Inserted %d\n", value);
}

int extractMax() {
    if (size <= 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int maxVal = heap[0];
    heap[0] = heap[size - 1]; // Move last element to root
    size--;
    heapifyDown(0);
    return maxVal;
}

void printHeap() {
    printf("Max Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(50); // Becomes root
    insert(30);
    insert(5);

    printHeap();

    printf("Extracted Max: %d\n", extractMax()); // Should be 50
    printHeap();

    return 0;
}

// Time Complexity: O(log N) for Insert/Extract
// Space Complexity: O(N)
