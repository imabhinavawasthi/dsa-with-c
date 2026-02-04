/*
 * Program: 22. Row-wise and column-wise sum
 * Language: C++
 * Description: Calculates the sum of each row and each column separately.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int sum;

    cout << "Original Matrix:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Row-wise Sum
    cout << "\nRow-wise Sum:" << endl;
    for(int i = 0; i < 3; i++) {
        sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
        cout << "Row " << i << " Sum = " << sum << endl;
    }

    // Column-wise Sum
    cout << "\nColumn-wise Sum:" << endl;
    for(int j = 0; j < 3; j++) { // Loop columns first
        sum = 0;
        for(int i = 0; i < 3; i++) { // Then loop rows
            sum += matrix[i][j];
        }
        cout << "Column " << j << " Sum = " << sum << endl;
    }

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(1).
