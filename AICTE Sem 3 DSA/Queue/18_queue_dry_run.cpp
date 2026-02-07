// File: 18_queue_dry_run.cpp
// Title: Queue Dry Run / Step-by-Step Visualization (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Shows state changes after operations.
// - Useful for viva explanation.

#include <iostream>
#include <iomanip>
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

    void printState(string op) {
        cout << left << setw(15) << op << " | Front: " << setw(2) << front << " | Rear: " << setw(2) << rear << " | Queue: ";
        if (front == -1) {
            cout << "EMPTY";
        } else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) return;
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
        
        printState("Enqueue(" + to_string(value) + ")");
    }

    void dequeue() {
        if (front == -1) return;
        front++;
        if (front > rear) {
            front = -1; // Reset
            rear = -1;
        }
        
        printState("Dequeue()");
    }
};

int main() {
    Queue q;

    cout << "\n--- Queue Dry Run (C++) ---\n";
    q.printState("Initial");

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(1)
