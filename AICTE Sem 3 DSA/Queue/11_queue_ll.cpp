// File: 11_queue_ll.cpp
// Title: Queue Implementation using Linked List (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Dynamic Queue using Classes and Pointers.
// - NO STL.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
             cout << "Queue Overflow! Heap memory exhausted." << endl;
             return;
        }

        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "\n--- Queue Operations (Linked List) using C++ ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

// Time Complexity:
// - O(1)

// Space Complexity:
// - O(n)
