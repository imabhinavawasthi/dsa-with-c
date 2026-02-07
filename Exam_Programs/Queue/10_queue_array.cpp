// File: 10_queue_array.cpp
// Title: Queue Implementation using Array (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Queue Implementation (FIFO).
// - Uses Class for Queue.

#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        int val = arr[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset
        }
        cout << "Dequeued: " << val << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "\n--- Queue Operations (Array) using C++ ---\n";
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
// - O(1) for insert/delete

// Space Complexity:
// - O(n)
