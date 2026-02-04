/*
 * Program: 19. Matrix subtraction
 * Language: C++
 * Description: Subtracts elements of second matrix from first matrix.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int mat1[2][2] = {
        {10, 20},
        {30, 40}
    };
    int mat2[2][2] = {
        {5, 5},
        {10, 10}
    };
    int diff[2][2];

    cout << "Matrix 1:" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) cout << mat1[i][j] << " ";
        cout << endl;
    }

    cout << "\nMatrix 2:" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) cout << mat2[i][j] << " ";
        cout << endl;
    }

    // Subtraction Logic
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    cout << "\nDifference Matrix:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(R * C).
