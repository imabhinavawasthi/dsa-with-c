/*
  File: binary_counter.cpp
  Title: Binary Counter Simulation (Amortized Analysis)
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program simulates a binary counter using an array to demonstrate Amortized Analysis.
  The cost of an 'increment' operation is determined by the number of bits flipped.
  
  Amortized Analysis Concept:
  - In the worst case, an increment can flip all k bits (e.g., 111...1 -> 000...0). Cost = k.
  - However, this happens very rarely.
  - Bit 0 flips every time (N times).
  - Bit 1 flips every 2nd time (N/2 times).
  - Bit 2 flips every 4th time (N/4 times).
  - ...
  - Bit i flips N / 2^i times.
  - Total flips < N * (1 + 1/2 + 1/4 + ... ) = 2N.
  - Thus, the amortized cost per operation is O(1).
*/

#include <iostream>
#include <iomanip> // For formatted output

using namespace std;

// Define the number of bits for the counter
const int BITS = 8;

class BinaryCounter {
private:
    int A[BITS]; // Array to store bits

public:
    // Constructor to initialize counter to 0
    BinaryCounter() {
        for (int i = 0; i < BITS; i++) {
            A[i] = 0;
        }
    }

    // Function to print the binary counter state
    void printCounter() {
        for (int i = BITS - 1; i >= 0; i--) {
            cout << A[i];
        }
    }

    // Function to increment the counter
    // Returns the cost (number of bit flips) for this operation
    int increment() {
        int i = 0;
        int cost = 0;

        // Flip 1s to 0s starting from LSB until a 0 is found
        while (i < BITS && A[i] == 1) {
            A[i] = 0;
            cost++; // 1 bit flip
            i++;
        }

        // Flip the first 0 to 1 (if within range)
        if (i < BITS) {
            A[i] = 1;
            cost++; // 1 bit flip
        }

        return cost;
    }
};

int main() {
    BinaryCounter counter;
    int n; // Number of increments

    cout << "=== Binary Counter Amortized Analysis ===" << endl;
    cout << "Enter number of increments to simulate: ";
    cin >> n;

    int total_cost = 0;
    
    cout << endl
         << left << setw(10) << "Operation" 
         << left << setw(15) << "Counter State" 
         << left << setw(10) << "Cost (Flips)" << endl;
    cout << "-----------------------------------------" << endl;
    
    // Initial state
    cout << left << setw(10) << "Start";
    counter.printCounter();
    cout << " " << left << setw(10) << 0 << endl;

    for (int k = 1; k <= n; k++) {
        int cost = counter.increment();
        total_cost += cost;

        cout << left << setw(10) << k;
        counter.printCounter();
        cout << " " << left << setw(10) << cost << endl;
    }

    cout << "-----------------------------------------" << endl;
    cout << "Total Operations (N): " << n << endl;
    cout << "Total Cost (Bit Flips): " << total_cost << endl;
    cout << "Amortized Cost (Total Cost / N): " << (float)total_cost / n << endl;

    cout << endl << "Analysis:" << endl;
    cout << "Notice that while some operations cost more (e.g., 4 or 5 flips)," << endl;
    cout << "the average cost never exceeds 2. This confirms O(1) amortized time." << endl;

    return 0;
}

/*
  // Worst Case Time Complexity (Single Operation): O(k) where k is number of bits
  // Amortized / Expected Time Complexity: O(1)
  // Space Complexity: O(k) for the array of bits
*/
