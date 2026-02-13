/*
  File: dynamic_array.cpp
  Title: Dynamic (Extendible) Array Implementation
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements a dynamic array that doubles its capacity when full.
  It tracks the number of copy operations to demonstrate Amortized Analysis.
  
  Note: STL vectors are NOT used. Manual memory management is demonstrated.

  Amortized Analysis Concept:
  - Most insertions take O(1) time (no resizing).
  - When the array is full (size = N), a resize operation occurs.
  - Resizing involves creating a new array of size 2N and copying N elements. Cost = N.
  - Total cost for N insertions = N (insertions) + (1 + 2 + 4 + ... + N/2 + N) (copying).
  - The series sum is approximately 2N.
  - Total time for N operations is O(N).
  - Amortized time per operation = O(N) / N = O(1).
*/

#include <iostream>
#include <iomanip>

using namespace std;

class DynamicArray {
private:
    int *array;
    int size;       // Current number of elements
    int capacity;   // Total available space

public:
    // Constructor
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        array = new int[capacity];
    }

    // Destructor to free memory
    ~DynamicArray() {
        delete[] array;
    }

    // Function to insert an element
    // Returns the cost (number of assignments/copies)
    int insert(int value) {
        int cost = 0;

        // Check if array is full
        if (size == capacity) {
            cout << "[Resize] Capacity full (" << capacity << "). Doubling to " << capacity * 2 << "." << endl;
            
            // Double the capacity
            int newCapacity = capacity * 2;
            int *newArray = new int[newCapacity];
            
            // Copy old elements to new array
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
                cost++; // Cost of copying
            }
            
            // Free old memory and update pointer
            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }

        // Insert the new element
        array[size] = value;
        size++;
        cost++; // Cost of inserting the new element

        return cost;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void printArray() const {
        cout << "Array Content: [ ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    int n;
    int initialCap = 2; // Start with small capacity to force resizing
    DynamicArray arr(initialCap);

    cout << "=== Dynamic Array Amortized Analysis ===" << endl;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << endl << "Starting with capacity: " << initialCap << endl;
    cout << "-----------------------------------------" << endl;
    cout << left << setw(10) << "Element" 
         << left << setw(10) << "Size" 
         << left << setw(10) << "Capacity" 
         << left << setw(10) << "Cost" << endl;
    cout << "-----------------------------------------" << endl;

    int total_cost = 0;

    for (int i = 1; i <= n; i++) {
        int val = i * 10; // Just some data
        int op_cost = arr.insert(val);
        total_cost += op_cost;

        cout << left << setw(10) << val 
             << left << setw(10) << arr.getSize() 
             << left << setw(10) << arr.getCapacity() 
             << left << setw(10) << op_cost << endl;
    }

    cout << "-----------------------------------------" << endl;
    cout << "Total Insertions: " << n << endl;
    cout << "Total Cost (Assignments): " << total_cost << endl;
    cout << "Amortized Cost (Total Cost / N): " << (float)total_cost / n << endl;

    cout << endl << "Analysis:" << endl;
    cout << "Notice that the 'Cost' spikes only when capacity doubles." << endl;
    cout << "Most operations have a cost of 1." << endl;
    cout << "The average cost remains constant (approx 3) regardless of N." << endl;

    return 0;
}

/*
  // Worst Case Time Complexity (Single Operation): O(N) when resizing
  // Amortized / Expected Time Complexity: O(1)
  // Space Complexity: O(N)
*/
