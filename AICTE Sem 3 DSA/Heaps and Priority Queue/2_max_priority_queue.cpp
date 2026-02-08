// File: 2_max_priority_queue.cpp
// Purpose: Implement Max Priority Queue using Binary Heap
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class MaxPriorityQueue {
    int heap[MAX_SIZE];
    int size;

public:
    MaxPriorityQueue() {
        size = 0;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Fix Upwards (Parent < Current -> Swap)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Fix Downwards (Find largest child)
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Queue Overflow" << endl;
            return;
        }
        heap[size] = value;
        size++;
        heapifyUp(size - 1);
        cout << "Inserted " << value << endl;
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1]; // Place last element at root
        size--;
        heapifyDown(0);
        return maxVal;
    }

    void printHeap() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;
    pq.insert(10);
    pq.insert(50);
    pq.insert(30);
    pq.insert(100); // New max

    pq.printHeap();

    cout << "Extracted Max: " << pq.extractMax() << endl; // Should be 100
    pq.printHeap();

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
