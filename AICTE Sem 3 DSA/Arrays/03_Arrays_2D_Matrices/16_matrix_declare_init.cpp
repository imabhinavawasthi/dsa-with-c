/*
 * Program: 16. Declare and initialize 2D array
 * Language: C++
 * Description: Demonstrates how to create a 2D array (matrix) and assign values.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    // 1. Declare and Initialize a 2x3 matrix (2 rows, 3 columns)
    int matrix[2][3] = {
        {10, 20, 30}, // Row 0
        {40, 50, 60}  // Row 1
    };

    cout << "2D Array Elements:" << endl;

    // 2. Access elements manually
    cout << "Element at [0][0]: " << matrix[0][0] << endl;
    cout << "Element at [0][1]: " << matrix[0][1] << endl;
    cout << "Element at [0][2]: " << matrix[0][2] << endl;
    cout << "Element at [1][0]: " << matrix[1][0] << endl;
    cout << "Element at [1][1]: " << matrix[1][1] << endl;
    cout << "Element at [1][2]: " << matrix[1][2] << endl;

    return 0;
}

// Time Complexity: O(1) for direct access.
// Space Complexity: O(R * C).
