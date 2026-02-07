// File: 14_circular_queue_full_empty.cpp
// Title: Circular Queue Full/Empty Conditions (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Demonstrates Full and Empty logic.
// - Demonstrates circular wrap-around.

#include <iostream>
using namespace std;

#define MAX 3

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << ". (Front: " << front << ", Rear: " << rear << ")" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << "Enqueued: " << value << ". (Front: " << front << ", Rear: " << rear << ")" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        int val = arr[front];
        cout << "Dequeued: " << val << ". (Front was: " << front << ")" << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
};

int main() {
    CircularQueue q;

    cout << "\n--- Circular Queue Full/Empty Demo ---\n";
    
    // 1. Fill
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // 2. Overflow
    cout << "Attempting to enqueue 40..." << endl;
    q.enqueue(40);

    // 3. Dequeue (Make space)
    q.dequeue();

    // 4. Wrap around
    cout << "Attempting to enqueue 40 again..." << endl;
    q.enqueue(40);

    // 5. Overflow
    cout << "Attempting to enqueue 50..." << endl;
    q.enqueue(50);

    return 0;
}

// Time Complexity:
// - O(1)

// Space Complexity:
// - O(1)
