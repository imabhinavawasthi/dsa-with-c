// File: 7_min_heap_modify.c
// Purpose: Decrease Key and Increase Key Operations
// Author: Abhinav Awasthi

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/*
 * Decrease Key (val < old_val):
 * - Update value.
 * - Since value decreased, it might be smaller than parent.
 * - Call Heapify UP.
 */
void decreaseKey(int arr[], int i, int newVal) {
    arr[i] = newVal;
    while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/*
 * Increase Key (val > old_val):
 * - Update value.
 * - Since value increased, it might be larger than children.
 * - Call Heapify DOWN.
 */
void increaseKey(int arr[], int size, int i, int newVal) {
    arr[i] = newVal;
    // Simple inline heapify down logic or call function
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // We only check once here (strictly speaking, should recursive/loop)
    // For completeness, loop logic:
    while (1) {
        smallest = i;
        left = 2 * i + 1;
        right = 2 * i + 2;

        if (left < size && arr[left] < arr[smallest]) smallest = left;
        if (right < size && arr[right] < arr[smallest]) smallest = right;

        if (smallest != i) {
            swap(&arr[i], &arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void printHeap(int arr[], int size) {
    for (int i=0; i<size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int heap[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;

    printf("Initial: "); printHeap(heap, size);

    printf("Decrease 50 (index 4) to 5:\n");
    decreaseKey(heap, 4, 5);
    printHeap(heap, size); // 5 should bubble up

    printf("Increase 10 (index 0) to 100:\n");
    increaseKey(heap, size, 0, 100);
    printHeap(heap, size); // 100 should sink down

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(1)
