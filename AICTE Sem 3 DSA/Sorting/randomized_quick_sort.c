/**
 * File: randomized_quick_sort.c
 * Algorithm: Randomized Quick Sort
 * 
 * Idea:
 * Same as Quick Sort, but the pivot is chosen randomly.
 * This reduces the chance of hitting the worst-case (O(n^2)) on sorted arrays.
 * 
 * Why it works:
 * By picking a random pivot, we expect to split the array more evenly on average.
 * Expected Time Complexity: O(n log n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
// Takes last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Randomized Partition
// Picks a random index between low and high, swaps it with high (pivot),
// and then calls standard partition.
int randomizedPartition(int arr[], int low, int high) {
    srand(time(NULL)); 
    int random = low + rand() % (high - low + 1);
    
    // Swap random element with last element (pivot)
    swap(&arr[random], &arr[high]);

    return partition(arr, low, high);
}

// Function to perform Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Use randomized partition
        int pi = randomizedPartition(arr, low, high);

        // Separately sort elements before and after partition
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("Sorted Array: \n");
    printArray(arr, n);

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n log n), O(n log n), O(n^2) (Worst case is very rare)
// Space Complexity: O(log n)
