// File: 5_min_heap_insert.cpp
// Purpose: Demonstrate Insert and Heapify-Up
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

#define MAX 100

class MinHeap {
    int heap[MAX];
    int size;

public:
    MinHeap() { size = 0; }

    void insert(int val) {
        heap[size] = val;
        int i = size;
        size++;

        // Heapify Up
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i] < heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            } else {
                break;
            }
        }
        printHeap(val);
    }

    void printHeap(int inserted) {
        cout << "Inserted " << inserted << ": ";
        for (int i=0; i<size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap mh;
    mh.insert(10);
    mh.insert(5);  // Causes swap
    mh.insert(3);  // Causes swap to root
    mh.insert(2);  // Causes swap to root
    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
