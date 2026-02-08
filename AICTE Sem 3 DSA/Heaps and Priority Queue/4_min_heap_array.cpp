// File: 4_min_heap_array.cpp
// Purpose: Demonstrate Array Representation of Min Heap
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

void printNodeDetails(int arr[], int size, int i) {
    cout << "Node Index: " << i << ", Value: " << arr[i] << endl;

    int p = (i - 1) / 2;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (i == 0)
        cout << " -> Root Node" << endl;
    else
        cout << " -> Parent Index: " << p << ", Value: " << arr[p] << endl;

    if (l < size)
        cout << " -> Left Child: " << arr[l] << endl;
    else
        cout << " -> No Left Child" << endl;

    if (r < size)
        cout << " -> Right Child: " << arr[r] << endl;
    else
        cout << " -> No Right Child" << endl;

    cout << endl;
}

int main() {
    int heap[] = {1, 3, 6, 5, 9, 8};
    int size = 6;

    cout << "Min Heap Array: 1, 3, 6, 5, 9, 8" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        printNodeDetails(heap, size, i);
    }

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
