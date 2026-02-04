/*
 * Program: 18. Matrix addition
 * Language: C++
 * Description: Adds two matrices cell by cell.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int sum[3][3];

    cout << "Matrix 1:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) cout << mat1[i][j] << " ";
        cout << endl;
    }

    cout << "\nMatrix 2:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) cout << mat2[i][j] << " ";
        cout << endl;
    }

    // Addition Logic
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "\nSum Matrix:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(R * C).
// Space Complexity: O(R * C).
