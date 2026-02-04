/*
 * Program: 20. Matrix multiplication
 * Language: C++
 * Description: Multiplies two matrices. Rows of 1st matrix must match Cols of 2nd.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int matA[2][2] = {{1, 2}, {3, 4}};
    int matB[2][2] = {{5, 6}, {7, 8}};
    int result[2][2] = {{0, 0}, {0, 0}}; // Initialize to 0

    cout << "Multiplying 2x2 Matrices..." << endl;

    // Matrix Multiplication Logic
    // Row of A * Col of B
    for(int i = 0; i < 2; i++) { // Rows of A
        for(int j = 0; j < 2; j++) { // Cols of B
            for(int k = 0; k < 2; k++) { // Common dimension
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    cout << "Result Matrix:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N^3) for square matrices.
// Space Complexity: O(N^2) for result matrix.
