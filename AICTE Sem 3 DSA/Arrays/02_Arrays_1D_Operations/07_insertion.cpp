/*
 * Program: 7. Insert an element at a given position
 * Language: C++
 * Description: Inserts a new element into an array at a specific index by shifting elements.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; // Current number of elements
    int pos, value;

    // 1. Display original array
    cout << "Original Array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2. Get input from user
    cout << "\nEnter position to insert (index 0 to " << n << "): ";
    cin >> pos;
    
    cout << "Enter value to insert: ";
    cin >> value;

    // 3. Validation
    if(pos < 0 || pos > n) {
        cout << "Invalid position! Please enter position between 0 and " << n << endl;
    } 
    else {
        // 4. Shift elements to the right to make space
        // Start from the last element and move backwards
        for(int i = n - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }

        // 5. Insert the new value at the correct position
        arr[pos] = value;
        n++; // Increase the count of elements

        // 6. Display updated array
        cout << "\nArray after insertion:" << endl;
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N) in worst case (inserting at index 0 requires shifting all elements).
// Space Complexity: O(1) auxiliary space.
