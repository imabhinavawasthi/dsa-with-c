/*
  File: quicksort_compare.c
  Title: Deterministic vs Randomized QuickSort Comparison
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program compares the performance of Deterministic QuickSort (Last Element Pivot)
  vs Randomized QuickSort on a WORST CASE input (Sorted Array).
  
  Performance Metric: Number of Comparisons.

  Logic:
  - We use a sorted array as input.
  - Deterministic QuickSort will pick the largest element as pivot every time.
    - This leads to O(N^2) complexity.
  - Randomized QuickSort will pick a random pivot.
    - This breaks the O(N^2) pattern, resulting in O(N log N) complexity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0; // Global counter for comparisons

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ---------------------------------------------------------
// DETERMINISTIC QUICKSORT (Last Element Pivot)
// ---------------------------------------------------------
int partitionDeterministic(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisons++; // Count comparison
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortDeterministic(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionDeterministic(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

// ---------------------------------------------------------
// RANDOMIZED QUICKSORT
// ---------------------------------------------------------
int partitionRandomized(int arr[], int low, int high) {
    // Randomized Pivot Selection
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisons++; // Count comparison
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortRandomized(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main() {
    int n;
    printf("=== QuickSort Comparison (Worst Case Input: Sorted Array) ===\n");
    printf("Enter array size (try 1000 or 2000): ");
    scanf("%d", &n);

    // Create two identical sorted arrays
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr1[i] = i; // Already sorted (0, 1, 2, ..., n-1)
        arr2[i] = i;
    }

    printf("\nRunning Deterministic QuickSort (Pivot = Last Element)...\n");
    comparisons = 0;
    quickSortDeterministic(arr1, 0, n - 1);
    printf("Deterministic Comparisons: %lld\n", comparisons);

    printf("\nRunning Randomized QuickSort (Pivot = Random)...\n");
    comparisons = 0;
    srand(time(NULL));
    quickSortRandomized(arr2, 0, n - 1);
    printf("Randomized Comparisons:    %lld\n", comparisons);

    printf("\nAnalysis:\n");
    printf("- Deterministic: comparisons approx N^2 / 2 (e.g., for N=1000, ~500,000)\n");
    printf("- Randomized: comparisons approx N log N (e.g., for N=1000, ~10,000)\n");
    printf("- Randomized is significantly faster for sorted inputs.\n");

    free(arr1);
    free(arr2);
    return 0;
}

/*
  // Comparisons vs Input Size N:
  // Deterministic (Sorted Input): O(N^2)
  // Randomized (Sorted Input):    O(N log N)
*/
