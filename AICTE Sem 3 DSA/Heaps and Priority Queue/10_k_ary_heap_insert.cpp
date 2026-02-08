// File: 10_k_ary_heap_insert.cpp
// Purpose: Implement K-ary Heap Insertion
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

#define MAX 100

class KAryHeap {
    int heap[MAX];
    int size;
    int K;

public:
    KAryHeap(int k) {
        K = k;
        size = 0;
    }

    void insert(int val) {
        if (size == MAX) return;

        heap[size] = val;
        int i = size;
        size++;

        // Heapify Up
        while (i > 0) {
            int parent = (i - 1) / K;
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
        cout << "Inserted " << val << endl;
    }

    void printHeap() {
        cout << K << "-ary Heap: ";
        for (int i=0; i<size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    int k = 3;
    cout << "Initializing " << k << "-ary Heap." << endl;
    KAryHeap kh(k);

    kh.insert(10);
    kh.insert(5);
    kh.insert(20);
    kh.insert(2); 

    kh.printHeap();

    return 0;
}

// Time Complexity: O(logK N)
// Space Complexity: O(N)
