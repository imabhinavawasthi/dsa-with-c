// File: 1_min_priority_queue.cpp
// Purpose: Implement Min Priority Queue using Binary Heap (Array Implementation)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class MinPriorityQueue {
    int heap[MAX_SIZE];
    int size;

public:
    MinPriorityQueue() {
        size = 0;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify Up (Bottom-Up approach for insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify Down (Top-Down approach for deletion)
    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
            
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest); // Recursively fix deeper levels
        }
    }

    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Queue Overflow" << endl;
            return;
        }
        heap[size] = value; // Add to end
        size++;
        heapifyUp(size - 1); // Fix Upwards
        cout << "Inserted " << value << endl;
    }

    int extractMin() {
        if (size <= 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap[size - 1]; // Replace root with last element
        size--;
        heapifyDown(0); // Fix Downwards
        return minVal;
    }

    void printHeap() {
        cout << "Heap Array: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);  // New min
    pq.insert(30);
    pq.insert(2);  // New min

    pq.printHeap();

    cout << "Extracted Min: " << pq.extractMin() << endl; // Should be 2
    pq.printHeap();

    cout << "Extracted Min: " << pq.extractMin() << endl; // Should be 5
    pq.printHeap();

    return 0;
}

// Time Complexity: Insert O(log N), ExtractMin O(log N)
// Space Complexity: O(N)
