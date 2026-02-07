/**
 * File: linear_search.cpp
 * Algorithm: Linear Search
 * 
 * Idea:
 * Iterate through the array from the first element to the last.
 * Compare each element with the target key.
 * If a match is found, return the index.
 * If the loop finishes without finding the key, return -1.
 */

#include <iostream>
using namespace std;

// Function to perform Linear Search
// Returns index of key if found, otherwise returns -1
int linearSearch(int arr[], int n, int key) {
    // Iterate through all elements
    for (int i = 0; i < n; i++) {
        // Check if current element matches the key
        if (arr[i] == key) {
            return i; // Key found at index i
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {10, 50, 30, 70, 80, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    // Print array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Key to search: " << key << endl;

    // Perform Linear Search
    int result = linearSearch(arr, n, key);

    // Print Result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

// Time Complexity (Best, Average, Worst): O(1), O(n), O(n)
// Space Complexity: O(1)
