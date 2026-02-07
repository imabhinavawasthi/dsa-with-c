// File: 15_circular_queue_traverse.cpp
// Title: Traverse Circular Queue (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Iterating elements from Front to Rear in a circular buffer.

#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % MAX == front) return;
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = value;
    }

    void traverse() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue Elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    CircularQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "\n--- Circular Queue Traversal ---\n";
    q.traverse();

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(1)
