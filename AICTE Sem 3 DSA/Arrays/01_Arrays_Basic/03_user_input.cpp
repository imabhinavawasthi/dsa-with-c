/*
 * Program: 3. Input array elements from user
 * Language: C++
 * Description: Takes input from the user to fill an array and then prints it.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int n, i;
    int arr[100]; // Declare a large enough array (Static allocation)

    // 1. Ask user for the number of elements
    cout << "Enter the number of elements (max 100): ";
    cin >> n;

    // Validate input
    if (n > 100 || n <= 0) {
        cout << "Invalid size! Please enter a number between 1 and 100." << endl;
        return 1;
    }

    // 2. Input elements using a loop
    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }

    // 3. Print the elements to verify
    cout << "\nThe elements you entered are:" << endl;
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(N) because we iterate through the loop N times.
// Space Complexity: O(100) -> O(1) constant space allocated.
