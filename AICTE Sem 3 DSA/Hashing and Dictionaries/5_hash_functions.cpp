/*
 * File: 5_hash_functions.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates Hash Functions used in Hash Tables.
 *
 * Covered Methods:
 * 1. Integer Hashing (Modulo)
 * 2. String Hashing (ASCII Sum - Naive)
 * 3. String Hashing (Polynomial Rolling Hash - Robust)
 *
 * Useful for understanding how keys are converted to array indices.
 */

#include <iostream>
#include <string>
using namespace std;

class HashFunctionDemo {
private:
    int m; // Table Size

public:
    HashFunctionDemo(int size) {
        m = size;
    }

    // 1. Integer Hash Function
    int hashInt(int key) {
        return key % m;
    }

    // 2. String Hash - ASCII Sum
    int hashStringSum(string key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % m;
    }

    // 3. String Hash - Polynomial Rolling Hash
    // hash = (hash * 31 + char) % m
    int hashStringPoly(string key) {
        long long hash = 0;
        const int p = 31;
        
        for (char c : key) {
            hash = (hash * p + c) % m;
        }
        return (int)(hash < 0 ? hash + m : hash);
    }
};

int main() {
    int m, choice, intKey;
    string strKey;

    cout << "Enter Hash Table Size (m): ";
    cin >> m;

    HashFunctionDemo hf(m);

    while (true) {
        cout << "\n--- Hash Function Design (C++) ---" << endl;
        cout << "1. Hash Integer (Modulo)" << endl;
        cout << "2. Hash String (ASCII Sum)" << endl;
        cout << "3. Hash String (Polynomial Rolling Hash)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Integer Key: ";
                cin >> intKey;
                cout << "Hash Value: " << hf.hashInt(intKey) << endl;
                break;
            case 2:
                cout << "Enter String Key: ";
                cin >> strKey;
                cout << "Hash Value (ASCII Sum): " << hf.hashStringSum(strKey) << endl;
                break;
            case 3:
                cout << "Enter String Key: ";
                cin >> strKey;
                cout << "Hash Value (Polynomial): " << hf.hashStringPoly(strKey) << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

// Time Complexity:
// Integer Hash: O(1)
// String Hash: O(L) where L is string length.
