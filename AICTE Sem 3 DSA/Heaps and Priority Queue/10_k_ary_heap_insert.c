// File: 10_k_ary_heap_insert.c
// Purpose: Implement K-ary Heap Insertion
// Author: Abhinav Awasthi

#include <stdio.h>

#define MAX 100

/*
 * K-ary Heap:
 * - Each node has K children instead of 2.
 * - Formulas (0-based):
 *   - Parent of i: (i - 1) / K
 *   - Children of i: K * i + 1  to  K * i + K
 * 
 * - Comparison with Binary Heap:
 *   - Binary: K=2. Height = log2(N).
 *   - K-ary: Height = logK(N). Height is smaller.
 *   - Decrease Key is faster (less height to bubble up).
 *   - Extract Min is slower (must compare K children).
 */

int heap[MAX];
int size = 0;
int K = 3; // Example: 3-ary Heap

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void insert(int val) {
    if (size == MAX) return;
    
    heap[size] = val;
    int i = size;
    size++;

    // Heapify Up for K-ary Heap
    // Parent Formula: (i - 1) / K
    while (i > 0) {
        int parent = (i - 1) / K;
        if (heap[i] < heap[parent]) { // Min Heap
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
    printf("Inserted %d in %d-ary Heap.\n", val, K);
}

void printHeap() {
    printf("%d-ary Heap Array: ", K);
    for (int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    printf("Creating a 3-ary Min Heap...\n");
    insert(10);
    insert(20);
    insert(5);  // Should bubble up
    insert(30);
    insert(40);
    insert(2);  // Should bubble up to root

    printHeap();

    return 0;
}

// Time Complexity: O(logK N) for insertion
// Space Complexity: O(N)
