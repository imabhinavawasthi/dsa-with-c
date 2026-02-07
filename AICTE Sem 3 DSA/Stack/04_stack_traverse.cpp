// File: 04_stack_traverse.cpp
// Title: Stack Traversal / Display (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Demonstrates iterating and displaying stack elements.
// - Shows elements from Top to Bottom (LIFO) and Bottom to Top.

#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) return;
        arr[++top] = value;
    }

    // Standard Traversal (LIFO)
    void displayTopToBottom() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Top -> Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Physical Order Traversal
    void displayBottomToTop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Bottom -> Top): ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    /*
      Stack state:
      50 (Top)
      40
      30
      20
      10 (Bottom)
    */

    cout << "\n--- Stack Traversal Demonstration ---\n";
    s.displayTopToBottom();
    s.displayBottomToTop();

    return 0;
}

// Time Complexity:
// - Traversal: O(n)

// Space Complexity:
// - O(1)
