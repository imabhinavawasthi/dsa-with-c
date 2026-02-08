// File: 6_min_heap_delete.cpp
// Purpose: Demonstrate Delete Min and Heapify-Down
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

void heapifyDown(int arr[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    
    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapifyDown(arr, size, smallest);
    }
}

void deleteMin(int arr[], int &size) {
    if (size == 0) return;

    int minVal = arr[0];
    arr[0] = arr[size - 1];
    size--;

    heapifyDown(arr, size, 0);

    cout << "Deleted " << minVal << ". Heap: ";
    for (int i=0; i<size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int heap[] = {2, 4, 6, 8, 10, 12};
    int size = 6;

    cout << "Initial: ";
    for (int x : heap) cout << x << " ";
    cout << endl;

    deleteMin(heap, size);
    deleteMin(heap, size);

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(log N)
