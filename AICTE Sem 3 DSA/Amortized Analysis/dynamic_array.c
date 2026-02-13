/*
  File: dynamic_array.c
  Title: Dynamic (Extendible) Array Implementation
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements a dynamic array that doubles its capacity when full.
  It tracks the number of copy operations to demonstrate Amortized Analysis.

  Amortized Analysis Concept:
  - Most insertions take O(1) time (no resizing).
  - When the array is full (size = N), a resize operation occurs.
  - Resizing involves creating a new array of size 2N and copying N elements. Cost = N.
  - Total cost for N insertions = N (insertions) + (1 + 2 + 4 + ... + N/2 + N) (copying).
  - The series sum is approximately 2N.
  - Total time for N operations is O(N).
  - Amortized time per operation = O(N) / N = O(1).
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for Dynamic Array
typedef struct {
    int *array;
    int size;       // Current number of elements
    int capacity;   // Total available space
} DynamicArray;

// Function to initialize the dynamic array
void initArray(DynamicArray *arr, int initialCapacity) {
    arr->array = (int *)malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
}

// Function to insert an element
// Returns the cost (number of assignments/copies)
int insert(DynamicArray *arr, int value) {
    int cost = 0;

    // Check if array is full
    if (arr->size == arr->capacity) {
        printf("[Resize] Capacity full (%d). Doubling to %d.\n", arr->capacity, arr->capacity * 2);
        
        // Double the capacity
        int newCapacity = arr->capacity * 2;
        int *newArray = (int *)malloc(newCapacity * sizeof(int));
        
        // Copy old elements to new array
        for (int i = 0; i < arr->size; i++) {
            newArray[i] = arr->array[i];
            cost++; // Cost of copying
        }
        
        // Free old memory and update pointer
        free(arr->array);
        arr->array = newArray;
        arr->capacity = newCapacity;
    }

    // Insert the new element
    arr->array[arr->size] = value;
    arr->size++;
    cost++; // Cost of inserting the new element

    return cost;
}

// Function to print array elements
void printArray(DynamicArray *arr) {
    printf("Array Content: [ ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("]\n");
}

int main() {
    DynamicArray arr;
    int n, initialCap = 2; // Start with small capacity to force resizing

    initArray(&arr, initialCap);

    printf("=== Dynamic Array Amortized Analysis ===\n");
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("\nStarting with capacity: %d\n", initialCap);
    printf("-----------------------------------------\n");
    printf("%-10s %-10s %-10s %-10s\n", "Element", "Size", "Capacity", "Cost");
    printf("-----------------------------------------\n");

    int total_cost = 0;

    for (int i = 1; i <= n; i++) {
        int val = i * 10; // Just some data
        int op_cost = insert(&arr, val);
        total_cost += op_cost;

        printf("%-10d %-10d %-10d %-10d\n", val, arr.size, arr.capacity, op_cost);
    }

    printf("-----------------------------------------\n");
    printf("Total Insertions: %d\n", n);
    printf("Total Cost (Assignments): %d\n", total_cost);
    printf("Amortized Cost (Total Cost / N): %.2f\n", (float)total_cost / n);

    printf("\nAnalysis:\n");
    printf("Notice that the 'Cost' spikes only when capacity doubles.\n");
    printf("Most operations have a cost of 1.\n");
    printf("The average cost remains constant (approx 3) regardless of N.\n");

    // Cleanup
    free(arr.array);

    return 0;
}

/*
  // Worst Case Time Complexity (Single Operation): O(N) when resizing
  // Amortized / Expected Time Complexity: O(1)
  // Space Complexity: O(N)
*/
