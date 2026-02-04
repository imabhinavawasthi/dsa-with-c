/*
 * Program: 9. Linear Search
 * Language: C++
 * Description: Search for an element by checking each index sequentially.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 50, 30, 70, 80, 20};
    int n = 6;
    int target, found = 0;

    // 1. Input target from user
    cout << "Array: 10, 50, 30, 70, 80, 20" << endl;
    cout << "Enter element to search: ";
    cin >> target;

    // 2. Traverse array to find element
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            cout << "Element " << target << " found at index " << i << endl;
            found = 1;
            break; // Stop searching once found
        }
    }

    // 3. If element not found
    if(found == 0) {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

// Time Complexity: O(N) - Worst case we check all elements.
// Space Complexity: O(1).
