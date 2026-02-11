/*
 * File: 10_load_factor.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates the concept of LOAD FACTOR (alpha) in Hash Tables.
 *
 * Load Factor (alpha) = n / m
 * where:
 *   n = Number of elements in table
 *   m = Size of table
 *
 * Goal:
 * To clearly show how performance degrades as the Load Factor increases.
 * We simulate Linear Probing and count the number of probes (comparisons) needed
 * to insert elements as the table fills up.
 *
 * Observation:
 * - When alpha is low (< 0.5), collisions are rare (1 probe).
 * - As alpha approaches 1.0, collisions become frequent (many probes).
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

// Slot Status
enum Status { EMPTY, OCCUPIED };

typedef struct {
    int key;
    enum Status status;
} HashSlot;

HashSlot hashTable[SIZE];

// Function Prototypes
void init();
int insertWithProbeCount(int key);

int main() {
    init();
    
    // We will insert elements one by one and track probes
    // Keys will be random-ish or sequential to trigger collisions naturally
    int keys[] = {10, 30, 50, 70, 90, 110, 130, 25, 45, 65, 85, 105, 12, 32, 52, 72, 92, 112, 132}; 
    int n_elements = sizeof(keys) / sizeof(keys[0]);

    printf("\n--- Load Factor Demonstration (Table Size = %d) ---\n", SIZE);
    printf("| %-10s | %-12s | %-15s |\n", "Elements (n)", "Load Factor", "Probes to Insert");
    printf("|------------|--------------|-----------------|\n");

    for (int i = 0; i < n_elements; i++) {
        int probes = insertWithProbeCount(keys[i]);
        
        // Calculate Load Factor (alpha)
        // (i + 1) is current number of elements
        float alpha = (float)(i + 1) / SIZE;
        
        printf("| %-10d | %-12.2f | %-15d |\n", i + 1, alpha, probes);
    }
    
    printf("\nOBSERVATION:\n");
    printf("Notice how the number of probes increases drastically as Load Factor approaches 1.0.\n");
    printf("This is why we usually resize (Rehash) the table when alpha > 0.7.\n");

    return 0;
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].status = EMPTY;
    }
}

// Returns number of probes used to insert
int insertWithProbeCount(int key) {
    int index = key % SIZE;
    int probes = 0;

    // Linear Probing
    while (hashTable[index].status == OCCUPIED) {
        probes++; // Collision happened
        index = (index + 1) % SIZE; 
    }
    
    // Found empty slot
    probes++; // Counting the final success probe/check
    hashTable[index].key = key;
    hashTable[index].status = OCCUPIED;
    
    return probes;
}

// Time Complexity: O(1) if alpha is low. O(n) as alpha -> 1.
