/*
 * Program: 17. Input and print matrix
 * Language: C++
 * Description: Takes user input for a matrix and prints it in a proper format.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    int matrix[10][10]; // Max size 10x10

    cout << "Enter number of rows (max 10): ";
    cin >> rows;
    cout << "Enter number of columns (max 10): ";
    cin >> cols;

    // 1. Input Loop
    cout << "\nEnter elements:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // 2. Output Loop (Printing in Matrix form)
    cout << "\nThe Matrix is:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t"; // \t for tab spacing
        }
        cout << endl; // Newline after each row
    }

    return 0;
}

// Time Complexity: O(Rows * Cols).
// Space Complexity: O(1) auxiliary.
