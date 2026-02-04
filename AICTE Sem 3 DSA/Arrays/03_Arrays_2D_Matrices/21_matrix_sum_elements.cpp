/*
 * Program: 21. Sum of all elements
 * Language: C++
 * Description: Calculates the sum of all elements in a matrix.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int sum = 0;

    cout << "Matrix:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Calculating Sum
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }

    cout << "\nTotal Sum of all elements: " << sum << endl;

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(1).
