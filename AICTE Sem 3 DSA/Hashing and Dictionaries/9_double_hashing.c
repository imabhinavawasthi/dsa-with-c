/*
 * File: 9_double_hashing.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table using Double Hashing.
 *
 * Double Hashing is considered the best form of Open Addressing.
 * It uses a second hash function to determine the step size in case of collision.
 *
 * Formulas:
 * Hash Function 1: h1(k) = k % SIZE
 * Hash Function 2: h2(k) = PRIME - (k % PRIME)
 * Probe Sequence:  index = (h1(k) + i * h2(k)) % SIZE
 *
 * Rules:
 * 1. h2(k) must never return 0.
 * 2. Table Size and h2's PRIME should be relatively prime.
 *
 * Time Complexity:
 * - Average: O(1)
 * - Worst: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 11  // Prime size
#define PRIME 7  // Smaller prime for h2

enum Status { EMPTY, OCCUPIED, DELETED };

typedef struct {
    int key;
    int value;
    enum Status status;
} HashSlot;

HashSlot hashTable[SIZE];

// Function Prototypes
void init();
int hash1(int key);
int hash2(int key);
void insert(int key, int value);
int search(int key);
void deleteKey(int key);
void display();

int main() {
    init();

    int choice, key, value;

    while (1) {
        printf("\n--- Double Hashing Hash Table ---\n");
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

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].status = EMPTY;
    }
}

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return PRIME - (key % PRIME);
}

void insert(int key, int value) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    
    // Check update
    for (int i = 0; i < SIZE; i++) {
        int index = (h1 + i * h2) % SIZE;
        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
            printf("Key %d exists. Updating value.\n", key);
            hashTable[index].value = value;
            return;
        }
        if (hashTable[index].status == EMPTY) break;
    }

    // Insert
    for (int i = 0; i < SIZE; i++) {
        int index = (h1 + i * h2) % SIZE;
        
        if (hashTable[index].status != OCCUPIED) {
            hashTable[index].key = key;
            hashTable[index].value = value;
            hashTable[index].status = OCCUPIED;
            printf("Inserted (%d, %d) at Index %d (i=%d)\n", key, value, index, i);
            return;
        }
    }
    printf("Hash Table is Full!\n");
}

int search(int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h1 + i * h2) % SIZE;

        if (hashTable[index].status == EMPTY) return -1;

        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
            return hashTable[index].value;
        }
    }
    return -1;
}

void deleteKey(int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h1 + i * h2) % SIZE;

        if (hashTable[index].status == EMPTY) {
            printf("Key not found!\n");
            return;
        }

        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
            hashTable[index].status = DELETED;
            printf("Key %d deleted from Index %d.\n", key, index);
            return;
        }
    }
    printf("Key not found!\n");
}

void display() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].status == OCCUPIED) {
            printf("Index %d: [%d : %d]\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Index %d: ---\n", i);
        }
    }
}
