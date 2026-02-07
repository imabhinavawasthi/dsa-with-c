// File: 03_stack_overflow_underflow.cpp
// Title: Stack Overflow and Underflow Demonstration (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Stack Overflow: Trying to push into a full stack.
// - Stack Underflow: Trying to pop from an empty stack.
// - Uses a Class with a fixed small size array.

#include <iostream>
using namespace std;

#define MAX 3 // Small size for demonstration

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "[ERROR] Stack Overflow! Cannot push " << value << ". Stack is full (Limit: " << MAX << ")." << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "[ERROR] Stack Underflow! Cannot pop. Stack is already empty." << endl;
            return;
        }
        cout << "Popped: " << arr[top] << endl;
        top--;
    }
};

int main() {
    Stack s;

    cout << "\n--- Stack Overflow Demonstration ---\n";
    s.push(10);
    s.push(20);
    s.push(30);
    // This next push will cause Overflow
    cout << "Attempting to push 4th element..." << endl;
    s.push(40);

    cout << "\n--- Stack Underflow Demonstration ---\n";
    s.pop();
    s.pop();
    s.pop();
    // This next pop will cause Underflow
    cout << "Attempting to pop from empty stack..." << endl;
    s.pop();

    return 0;
}

// Time Complexity:
// - All operations are O(1)

// Space Complexity:
// - O(1) considering fixed small size
