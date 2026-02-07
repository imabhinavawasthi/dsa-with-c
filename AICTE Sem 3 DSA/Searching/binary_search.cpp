/**
 * File: binary_search.cpp
 * Algorithm: Binary Search (Iterative)
 * 
 * Idea:
 * Works only on SORTED arrays.
 * Keep two pointers: 'low' (start) and 'high' (end).
 * Find the middle element.
 * If middle element == key, return index.
 * If key < middle element, search in the left half (high = mid - 1).
 * If key > middle element, search in the right half (low = mid + 1).
 * Repeat until low > high.
 */

#include <iostream>
using namespace std;

// Function to perform Binary Search
// Returns index of key if found, otherwise returns -1
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2; // Calculate middle index

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is smaller, ignore right half
        if (arr[mid] > key) {
            high = mid - 1;
        }
        // If key is greater, ignore left half
        else {
            low = mid + 1;
        }
    }

    // Key not found
    return -1;
}

int main() {
    // Array MUST be sorted for Binary Search
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    // Print array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Key to search: " << key << endl;

    // Perform Binary Search
    int result = binarySearch(arr, n, key);

    // Print Result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

// Time Complexity (Best, Average, Worst): O(1), O(log n), O(log n)
// Space Complexity: O(1)
