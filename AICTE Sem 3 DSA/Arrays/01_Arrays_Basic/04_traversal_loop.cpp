/*
 * Program: 4. Traverse an array using a loop
 * Language: C++
 * Description: Demonstrates how to iterate through all elements of an array.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5; // Size of the array

    cout << "Traversing array elements:" << endl;

    // Standard for loop traversal
    for (int i = 0; i < n; i++) {
        // Access each element using index i
        cout << "Element at index " << i << " is " << arr[i] << endl;
    }

    return 0;
}

// Time Complexity: O(N) since we visit every element once.
// Space Complexity: O(1) auxiliary space.
