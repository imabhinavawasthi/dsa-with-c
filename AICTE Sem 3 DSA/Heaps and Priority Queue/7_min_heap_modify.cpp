// File: 7_min_heap_modify.cpp
// Purpose: Decrease Key and Increase Key Operations
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

void decreaseKey(int arr[], int i, int newVal) {
    arr[i] = newVal;
    while (i != 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void increaseKey(int arr[], int size, int i, int newVal) {
    arr[i] = newVal;
    
    // Heapify Down Loop
    while (true) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] < arr[smallest]) smallest = left;
        if (right < size && arr[right] < arr[smallest]) smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void printHeap(int arr[], int size) {
    for (int i=0; i<size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int heap[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Initial: "; printHeap(heap, size);

    cout << "Decrease 40 (index 3) to 5:" << endl;
    decreaseKey(heap, 3, 5);
    printHeap(heap, size);

    cout << "Increase 5 (index 0) to 100:" << endl;
    increaseKey(heap, size, 0, 100);
    printHeap(heap, size);

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(1)
