/*
 * File: 7_linear_probing.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table using Linear Probing (Open Addressing).
 *
 * Collision Resolution:
 * If a collision occurs at index 'i', we check (probe) the next index:
 * (i + 1) % SIZE, (i + 2) % SIZE, and so on...
 * until an empty slot is found.
 * 
 * Clustering Problem:
 * Linear Probing suffers from "Primary Clustering". Long runs of occupied slots build up,
 * increasing the average search time.
 *
 * Lazy Deletion:
 * When deleting a key, we cannot simply mark the slot as EMPTY, because it might
 * break the probe chain for other keys.
 * Solution: We check a special flag 'DELETED'.
 * - Insert can use DELETED slots.
 * - Search continues over DELETED slots.
 * - Search stops at EMPTY slots.
 *
 * Time Complexity:
 * - Average: O(1 / (1 - alpha))
 * - Worst: O(n) (Table full or bad clustering)
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Slot Status
enum Status { EMPTY, OCCUPIED, DELETED };

typedef struct {
    int key;
    int value;
    enum Status status;
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
        printf("\n--- Linear Probing Hash Table ---\n");
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

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    int start = index;

    // First pass to check if key already exists (Update)
    int tempIndex = index;
    while (hashTable[tempIndex].status != EMPTY) {
        if (hashTable[tempIndex].status == OCCUPIED && hashTable[tempIndex].key == key) {
            printf("Key %d already exists at Index %d. Updating value.\n", key, tempIndex);
            hashTable[tempIndex].value = value;
            return;
        }
        tempIndex = (tempIndex + 1) % SIZE;
        if (tempIndex == start) break; // Circled back
    }

    // Second pass to find insertion spot
    // We can insert at EMPTY or DELETED slots
    while (hashTable[index].status == OCCUPIED) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash Table is FULL!\n");
            return;
        }
    }

    // Found a spot (EMPTY or DELETED)
    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].status = OCCUPIED;
    printf("Inserted (%d, %d) at Index %d\n", key, value, index);
}

int search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index].status != EMPTY) {
        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % SIZE;
        if (index == start) break; // Circled back
    }
    return -1; // Not found
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index].status != EMPTY) {
        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
            hashTable[index].status = DELETED; // Lazy Deletion
            printf("Key %d deleted from Index %d.\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    printf("Key not found!\n");
}

void display() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].status == OCCUPIED) {
            printf("Index %d: [%d : %d]\n", i, hashTable[i].key, hashTable[i].value);
        } else if (hashTable[i].status == DELETED) {
            printf("Index %d: [DELETED]\n", i);
        } else {
            printf("Index %d: ---\n", i);
        }
    }
}
