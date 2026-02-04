/*
 * Program: 8. Delete an element from a given position
 * Language: C++
 * Description: Deletes an element from an array by shifting subsequent elements to the left.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; // Current number of elements
    int pos;

    // 1. Display original array
    cout << "Original Array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2. Get input from user
    cout << "\nEnter position to delete (index 0 to " << n - 1 << "): ";
    cin >> pos;

    // 3. Validation
    if(pos < 0 || pos >= n) {
        cout << "Invalid position! Please enter position between 0 and " << n - 1 << endl;
    } 
    else {
        // 4. Shift elements to the left to fill the gap
        // Start from the position to be deleted
        for(int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // 5. Decrease the count of elements
        n--; 

        // 6. Display updated array
        cout << "\nArray after deletion:" << endl;
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N) in worst case (deleting from index 0 requires shifting all elements).
// Space Complexity: O(1) auxiliary space.
