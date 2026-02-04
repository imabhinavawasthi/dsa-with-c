/*
 * Program: 14. Insertion with step-by-step shifting output
 * Language: C++
 * Description: Visualizes how elements shift to the right during insertion.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2; // Inserting at index 2
    int value = 99;

    cout << "Original Array: ";
    printArray(arr, n);

    cout << "\nInserting " << value << " at index " << pos << "..." << endl;
    
    // Shifting loop with visualization
    for(int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i]; // Move element one step right
        cout << "Shifted " << arr[i] << " to index " << i + 1 << ": ";
        printArray(arr, n + 1); // Print intermediate state
    }

    arr[pos] = value; // Insert value
    n++; // Increment size

    cout << "\nFinal Array: ";
    printArray(arr, n);

    return 0;
}

// Time Complexity: O(N) - Shifting elements.
// Space Complexity: O(1).
