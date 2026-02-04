/*
 * Program: 6. Find array length using sizeof
 * Language: C++
 * Description: Calculates the number of elements in an array using the sizeof operator.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};

    // sizeof(arr) gives total bytes occupied by the array
    // sizeof(arr[0]) gives bytes occupied by one element
    
    // Formula: Length = Total Bytes / Bytes per Element
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total size of array in bytes: " << sizeof(arr) << endl;
    cout << "Size of one element (int): " << sizeof(arr[0]) << endl;
    cout << "Number of elements in array: " << n << endl;

    return 0;
}

// Time Complexity: O(1) - Computed at compile time.
// Space Complexity: O(1).
