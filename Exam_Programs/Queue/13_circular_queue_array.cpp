// File: 13_circular_queue_array.cpp
// Title: Circular Queue Implementation using Array (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Circular Queue to overcome limitation of linear queue (space wastage).
// - Uses (index + 1) % MAX logic.

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

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) front = 0;
        
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        int val = arr[front];
        if (front == rear) { // Last element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        cout << "Dequeued: " << val << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Circular Queue: ";
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
    int choice, value;

    cout << "\n--- Circular Queue Operations (C++) ---\n";
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
