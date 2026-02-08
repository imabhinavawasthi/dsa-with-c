// File: 5_min_heap_insert.c
// Purpose: Demonstrate Insert and Heapify-Up Logic
// Author: Abhinav Awasthi

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void printHeap() {
    for (int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n");
}

/*
 * Heapify Up:
 * 1. Compare node with parent: (i - 1) / 2
 * 2. If node < parent, SWAP.
 * 3. Repeat until root or parent is smaller.
 */
void insert(int val) {
    if (size == MAX) return;

    // 1. Insert at end
    heap[size] = val;
    int current = size;
    size++;

    // 2. Fix Heap Property (Heapify Up)
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current] < heap[parent]) {
            swap(&heap[current], &heap[parent]);
            current = parent;
        } else {
            break;
        }
    }
    
    printf("After inserting %d: ", val);
    printHeap();
}

int main() {
    // Insert in specific order to trigger swaps
    insert(50);
    insert(30); // Swap with 50
    insert(20); // Swap with 30
    insert(15); // Swap with 20...
    insert(10); // Bubble up to root
    insert(8);  // Bubble up to root

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
