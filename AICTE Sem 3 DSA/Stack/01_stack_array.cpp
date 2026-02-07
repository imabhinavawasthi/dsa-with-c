// File: 01_stack_array.cpp
// Title: Stack Implementation using Array (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Stack is a LIFO (Last In First Out) data structure.
// - This implementation uses a Class with private array and public methods.
// - NO STL is used.

#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor to initialize stack
    Stack() {
        top = -1; // Stack is initially empty
    }

    // Function to check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Function to push an element
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        top++;              // Increment top
        arr[top] = value;   // Insert value at top
        cout << "Pushed " << value << " onto stack." << endl;
    }

    // Function to pop an element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        int poppedValue = arr[top];
        top--;              // Decrement top
        cout << "Popped element: " << poppedValue << endl;
    }

    // Function to peek the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // Function to display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (Top to Bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    cout << "\n--- Stack Operations (Array) using C++ ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

// Time Complexity:
// - Push: O(1)
// - Pop: O(1)
// - Peek: O(1)
// - Display: O(n)

// Space Complexity:
// - O(n) where n is the size of the stack
