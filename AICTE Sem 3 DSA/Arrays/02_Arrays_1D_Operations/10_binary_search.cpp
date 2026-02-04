/*
 * Program: 10. Binary Search (Iterative)
 * Language: C++
 * Description: Efficiently search in a SORTED array by dividing the search range in half.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    // Array MUST be sorted for Binary Search
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;
    int target, low, high, mid, found = 0;

    cout << "Sorted Array: 10, 20, 30, 40, 50, 60, 70, 80, 90" << endl;
    cout << "Enter element to search: ";
    cin >> target;

    // Initialize pointers
    low = 0;
    high = n - 1;

    // Search Loop
    while(low <= high) {
        // Calculate middle index
        mid = (low + high) / 2;

        if(arr[mid] == target) {
            cout << "Element found at index " << mid << endl;
            found = 1;
            break; // Found
        }
        else if(arr[mid] < target) {
            // Target is in the right half
            low = mid + 1;
        }
        else {
            // Target is in the left half
            high = mid - 1;
        }
    }

    if(found == 0) {
        cout << "Element not found." << endl;
    }

    return 0;
}

// Time Complexity: O(log N) - Search space is halved in every step.
// Space Complexity: O(1) - Iterative approach uses constant space.
