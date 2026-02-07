/**
 * File: quick_select.cpp
 * Algorithm: Kth Smallest Element (Quick Select)
 * 
 * Idea:
 * Uses Partition logic from Quick Sort.
 * If pivot is at index 'k-1', then pivot is the kth smallest element.
 * If pivot index > 'k-1', recurse for left subarray.
 * If pivot index < 'k-1', recurse for right subarray.
 * 
 * Time Complexity:
 * Average: O(n)
 * Worst: O(n^2)
 */

#include <iostream>
using namespace std;

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

// Function to find kth smallest element
int kthSmallest(int arr[], int low, int high, int k) {
    // If k is smaller than number of elements in array
    if (k > 0 && k <= high - low + 1) {
        
        // Partition the array
        int pi = partition(arr, low, high);

        // If position is same as k
        if (pi - low == k - 1)
            return arr[pi];

        // If position is more, recur for left subarray
        if (pi - low > k - 1)
            return kthSmallest(arr, low, pi - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pi + 1, high, k - pi + low - 1);
    }

    // Usually shouldn't reach here if k is valid
    return -1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Find " << k << "-th smallest element" << endl;
    
    int result = kthSmallest(arr, 0, n - 1, k);
    
    cout << k << "-th smallest element is " << result << endl;

    return 0;
}

// Time Complexity (Best, Average, Worst): O(n), O(n), O(n^2)
// Space Complexity: O(log n)
