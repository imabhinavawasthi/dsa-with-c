/*
  File: binary_counter.c
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of bits for the counter
#define BITS 8 

// Function to print the binary counter state
void printCounter(int *A) {
    for (int i = BITS - 1; i >= 0; i--) {
        printf("%d", A[i]);
    }
}

// Function to increment the counter
// Returns the cost (number of bit flips) for this operation
int increment(int *A) {
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

int main() {
    int A[BITS] = {0}; // Initialize counter to 0
    int n; // Number of increments

    printf("=== Binary Counter Amortized Analysis ===\n");
    printf("Enter number of increments to simulate: ");
    scanf("%d", &n);

    int total_cost = 0;
    
    printf("\n%-10s %-15s %-10s\n", "Operation", "Counter State", "Cost (Flips)");
    printf("-----------------------------------------\n");
    
    // Initial state
    printf("%-10s ", "Start");
    printCounter(A);
    printf(" %-10d\n", 0);

    for (int k = 1; k <= n; k++) {
        int cost = increment(A);
        total_cost += cost;

        printf("%-10d ", k);
        printCounter(A);
        printf(" %-10d\n", cost);
    }

    printf("-----------------------------------------\n");
    printf("Total Operations (N): %d\n", n);
    printf("Total Cost (Bit Flips): %d\n", total_cost);
    printf("Amortized Cost (Total Cost / N): %.2f\n", (float)total_cost / n);

    printf("\nAnalysis:\n");
    printf("Notice that while some operations cost more (e.g., 4 or 5 flips),\n");
    printf("the average cost never exceeds 2. This confirms O(1) amortized time.\n");

    return 0;
}

/*
  // Worst Case Time Complexity (Single Operation): O(k) where k is number of bits
  // Amortized / Expected Time Complexity: O(1)
  // Space Complexity: O(k) for the array of bits
*/
