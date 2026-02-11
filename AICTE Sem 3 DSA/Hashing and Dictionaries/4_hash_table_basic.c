/*
 * File: 4_hash_table_basic.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Basic Hash Table using a simple Hash Function.
 * Hash Function: h(k) = Resultant Index = k % size
 *
 * NOTE:
 * This implementation DOES NOT handle collisions effectively.
 * If two keys map to the same index, the old value is OVERWRITTEN.
 * This demonstrates why Collision Resolution strategies (like Chaining or Probing)
 * are necessary (covered in later programs).
 *
 * Operations:
 * 1. Insert: Calculate index and store.
 * 2. Search: Calculate index and check.
 * 3. Delete: Calculate index and clear.
 *
 * Time Complexity:
 * - Insert: O(1)
 * - Search: O(1)
 * - Delete: O(1)
 *
 * Space Complexity: O(m) where m is table size.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Hash Table Structure
typedef struct {
    int key;
    int value;
    int is_occupied; // Flag to check if slot is empty (0) or full (1)
} HashSlot;

HashSlot hashTable[SIZE];

// Function Prototypes
void init();
int hashFunction(int key);
void insert(int key, int value);
int search(int key);
void deleteKey(int key);
void display();

int main() {
    init();

    int choice, key, value;

    while (1) {
        printf("\n--- Basic Hash Table (No Collision Handling) ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int val = search(key);
                if (val != -1) {
                    printf("Key found! Value: %d\n", val);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Initialize Hash Table
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].is_occupied = 0;
    }
}

// Simple Modulus Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);

    if (hashTable[index].is_occupied) {
        printf("WARNING: Collision at index %d! Old value (Key: %d) overwritten by New (Key: %d).\n", 
               index, hashTable[index].key, key);
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].is_occupied = 1;
    printf("Inserted (%d, %d) at Index %d\n", key, value, index);
}

int search(int key) {
    int index = hashFunction(key);

    if (hashTable[index].is_occupied && hashTable[index].key == key) {
        return hashTable[index].value;
    }
    return -1; // Not found
}

void deleteKey(int key) {
    int index = hashFunction(key);

    if (hashTable[index].is_occupied && hashTable[index].key == key) {
        hashTable[index].is_occupied = 0;
        printf("Key %d deleted from Index %d.\n", key, index);
    } else {
        printf("Key not found!\n");
    }
}

void display() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].is_occupied) {
            printf("Index %d: [%d : %d]\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Index %d: ---\n", i);
        }
    }
}

// Time Complexity (Average & Worst Case):
// Insert: O(1)
// Search: O(1)
// Delete: O(1)
// Space Complexity: O(m)
