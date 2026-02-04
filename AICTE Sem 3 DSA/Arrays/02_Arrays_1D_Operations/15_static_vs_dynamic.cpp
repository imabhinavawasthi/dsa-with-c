/*
 * Program: 15. Static array vs dynamic array
 * Language: C++
 * Description: Shows difference between stack-allocated (static) and heap-allocated (dynamic) arrays.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    // 1. Static Array (Allocated on Stack)
    int staticArr[5] = {1, 2, 3, 4, 5};
    
    cout << "Static Array (Stack): " << staticArr[0] << " " << staticArr[1] << endl;

    // 2. Dynamic Array (Allocated on Heap)
    int n;
    int *dynamicArr;

    cout << "\nEnter size for dynamic array: ";
    cin >> n;

    // 'new' operator allocates memory on Heap
    dynamicArr = new int[n]; 

    // Input elements
    cout << "Enter elements for dynamic array:" << endl;
    for(int i = 0; i < n; i++) {
        dynamicArr[i] = (i + 1) * 10; // Auto-filling examples
    }

    // Printing
    cout << "Dynamic Array (Heap): ";
    for(int i = 0; i < n; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    // IMPORTANT: Always delete dynamically allocated memory!
    delete[] dynamicArr; // delete[] is used for arrays
    cout << "Memory freed successfully." << endl;

    return 0;
}

// Time Complexity: O(N) for allocation/access.
// Space Complexity: O(N) on Heap.
