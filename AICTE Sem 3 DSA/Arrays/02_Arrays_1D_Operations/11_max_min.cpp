/*
 * Program: 11. Find maximum and minimum element
 * Language: C++
 * Description: Finds the largest and smallest numbers in an array efficiently.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] = {15, 30, 10, 50, 25, 5, 45};
    int n = 7;
    int max, min;

    cout << "Array: 15, 30, 10, 50, 25, 5, 45" << endl;

    // Initialize max and min with the first element
    max = arr[0];
    min = arr[0];

    // Traverse the rest of the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if current element is larger
        }
        
        if (arr[i] < min) {
            min = arr[i]; // Update min if current element is smaller
        }
    }

    cout << "Maximum element is: " << max << endl;
    cout << "Minimum element is: " << min << endl;

    return 0;
}

// Time Complexity: O(N) - We traverse the array once.
// Space Complexity: O(1).
