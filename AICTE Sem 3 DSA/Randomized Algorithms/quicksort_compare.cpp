/*
  File: quicksort_compare.cpp
  Title: Deterministic vs Randomized QuickSort Comparison
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program compares the performance of Deterministic QuickSort (Last Element Pivot)
  vs Randomized QuickSort on a WORST CASE input (Sorted Array).
  
  Performance Metric: Number of Comparisons.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    cout << "=== QuickSort Comparison (Worst Case Input: Sorted Array) ===" << endl;
    cout << "Enter array size (try 1000 or 2000): ";
    cin >> n;

    // Create two identical sorted arrays
    int *arr1 = new int[n];
    int *arr2 = new int[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = i; // Already sorted (0, 1, 2, ..., n-1)
        arr2[i] = i;
    }

    cout << endl << "Running Deterministic QuickSort (Pivot = Last Element)..." << endl;
    comparisons = 0;
    quickSortDeterministic(arr1, 0, n - 1);
    cout << "Deterministic Comparisons: " << comparisons << endl;

    cout << endl << "Running Randomized QuickSort (Pivot = Random)..." << endl;
    comparisons = 0;
    srand(time(NULL));
    quickSortRandomized(arr2, 0, n - 1);
    cout << "Randomized Comparisons:    " << comparisons << endl;

    cout << endl << "Analysis:" << endl;
    cout << "- Deterministic: comparisons approx N^2 / 2" << endl;
    cout << "- Randomized: comparisons approx N log N" << endl;
    cout << "- Randomized is significantly faster for sorted inputs." << endl;

    delete[] arr1;
    delete[] arr2;
    return 0;
}

/*
  // Comparisons vs Input Size N:
  // Deterministic (Sorted Input): O(N^2)
  // Randomized (Sorted Input):    O(N log N)
*/
