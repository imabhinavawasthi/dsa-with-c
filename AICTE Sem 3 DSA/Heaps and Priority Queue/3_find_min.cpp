// File: 3_find_min.cpp
// Purpose: Demonstrate findMin operation in Min Heap
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

class MinHeap {
    int* heap;
    int size;

public:
    MinHeap(int arr[], int s) {
        heap = arr;
        size = s;
    }

    int findMin() {
        if (size == 0) {
            cout << "Heap Empty" << endl;
            return -1;
        }
        // Min is always root
        return heap[0];
    }
};

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = 5;
    
    MinHeap mh(arr, n);

    cout << "Heap Array: 5 10 15 20 25" << endl;
    cout << "Minimum Element: " << mh.findMin() << endl;
    cout << "Time Complexity: O(1)" << endl;

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
