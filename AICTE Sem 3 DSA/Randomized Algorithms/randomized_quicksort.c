/*
  File: randomized_quicksort.c
  Title: Randomized QuickSort Implementation
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements Randomized QuickSort.
  The key difference from Deterministic QuickSort is the selection of the pivot.
  
  Logic:
  - In Deterministic QuickSort, we often pick the last element as pivot.
    - worst case O(N^2) if array is already sorted.
  - In Randomized QuickSort, we pick a random index in [low, high] range.
    - We swap this random element with the last element.
    - Then we proceed with standard partition.
  
  Complexity:
  - By picking a random pivot, we avoid checking worst-case patterns (like sorted arrays).
  - The expected running time becomes O(N log N).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard Partition Function
// Takes last element as pivot and places it in correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot is the last element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Randomized Partition Function
// Picks a random pivot, swaps with last element, then calls standard partition
int randomizedPartition(int arr[], int low, int high) {
    // Generate random index between low and high
    srand(time(NULL)); // Seed the random number generator
    int random = low + rand() % (high - low + 1);

    // Swap random element with the last element (pivot position)
    swap(&arr[random], &arr[high]);

    return partition(arr, low, high);
}

// Randomized QuickSort Function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = randomizedPartition(arr, low, high);

        // Recursively sort elements before and after partition
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("=== Randomized QuickSort ===\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: \n");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("\nSorted Array: \n");
    printArray(arr, n);

    free(arr);
    return 0;
}

/*
  // Worst Case Time Complexity: O(N^2) (Extremely rare, only if random pivot consistently picks worst candidate)
  // Amortized / Expected Time Complexity: O(N log N)
  // Space Complexity: O(log N) (Recursion stack space)
*/
