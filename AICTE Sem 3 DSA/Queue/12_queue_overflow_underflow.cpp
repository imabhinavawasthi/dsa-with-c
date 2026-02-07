// File: 12_queue_overflow_underflow.cpp
// Title: Queue Overflow and Underflow Demonstration (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Demonstrates Queue full and empty conditions.
// - Uses small fixed size.

#include <iostream>
using namespace std;

#define MAX 3

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
            cout << "[ERROR] Queue Overflow! Cannot enqueue " << value << ". Queue is full." << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "[ERROR] Queue Underflow! Cannot dequeue. Queue is empty." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }
};

int main() {
    Queue q;

    cout << "\n--- Queue Overflow Demo ---\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Attempting 4th enqueue..." << endl;
    q.enqueue(40);

    cout << "\n--- Queue Underflow Demo ---\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Attempting 4th dequeue..." << endl;
    q.dequeue();

    return 0;
}

// Time Complexity:
// - O(1)

// Space Complexity:
// - O(1)
