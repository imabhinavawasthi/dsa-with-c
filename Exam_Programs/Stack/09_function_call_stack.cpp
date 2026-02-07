// File: 09_function_call_stack.cpp
// Title: Function Call Stack Demonstration (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Visualizes the System Stack (Call Stack) used during recursion.
// - Shows Push (Call) and Pop (Return) operations implicitly.

#include <iostream>
using namespace std;

void functionC(int n) {
    cout << "[PUSH] Inside functionC(" << n << "). Stack frame created." << endl;
    cout << "[POP]  Exiting functionC(" << n << "). Stack frame destroyed." << endl;
}

void functionB(int n) {
    cout << "[PUSH] Inside functionB(" << n << "). Stack frame created." << endl;
    functionC(n + 1);
    cout << "[POP]  Exiting functionB(" << n << "). Stack frame destroyed." << endl;
}

void functionA(int n) {
    cout << "[PUSH] Inside functionA(" << n << "). Stack frame created." << endl;
    functionB(n + 1);
    cout << "[POP]  Exiting functionA(" << n << "). Stack frame destroyed." << endl;
}

// Recursive Factorial
int factorial(int n) {
    cout << "[PUSH] Factorial(" << n << ") called." << endl;
    if (n <= 1) {
        cout << "[BASE] Base case reached at n=" << n << ". Returning 1." << endl;
        return 1;
    }
    int result = n * factorial(n - 1);
    cout << "[POP]  Factorial(" << n << ") returning " << result << "." << endl;
    return result;
}

int main() {
    cout << "\n--- Simple Call Stack Demo ---" << endl;
    cout << "[MAIN] Starting Main..." << endl;
    functionA(1);
    cout << "[MAIN] Back in Main." << endl;

    cout << "\n--- Recursive Factorial Demo ---" << endl;
    int n = 3;
    cout << "Result of Factorial(" << n << "): " << factorial(n) << endl;

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n) recursion stack
