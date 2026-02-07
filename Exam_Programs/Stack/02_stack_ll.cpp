// File: 02_stack_ll.cpp
// Title: Stack Implementation using Linked List (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Uses a Linked List to implement Stack.
// - Uses 'new' and 'delete' for dynamic memory allocation.
// - NO STL is used.

#include <iostream>
using namespace std;

// Class for a Node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Function to push an element
    void push(int value) {
        // 1. Create new node using 'new'
        Node* newNode = new Node(value);

        if (!newNode) {
             cout << "Stack Overflow! Heap memory exhausted." << endl;
             return;
        }

        // 2. Link new node to current top
        newNode->next = top;

        // 3. Update top
        top = newNode;

        cout << "Pushed " << value << " onto stack." << endl;
    }

    // Function to pop an element
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        // 1. Store temp pointer
        Node* temp = top;

        // 2. Move top
        top = top->next;

        // 3. Print and delete
        cout << "Popped element: " << temp->data << endl;
        delete temp;
    }

    // Function to peek top element
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    // Function to display stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack elements (Top to Bottom):" << endl;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free all memory when stack object is destroyed
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    cout << "\n--- Stack Operations (Linked List) using C++ ---\n";
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
// - O(n) where n is the number of nodes
