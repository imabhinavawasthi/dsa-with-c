/*
 * File: 8_quadratic_probing.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table using Quadratic Probing.
 *
 * Collision Resolution:
 * If collision occurs at index 'h', we try:
 * (h + 1^2) % SIZE, (h + 2^2) % SIZE, (h + 3^2) % SIZE...
 * i.e., h, h+1, h+4, h+9...
 *
 * Advantages:
 * - Reduces "Primary Clustering" seen in Linear Probing.
 *
 * Disadvantages:
 * - "Secondary Clustering": Keys hashing to same initial index follow same path.
 * - Might not find an empty slot even if one exists (unless table size is prime and < 50% full).
 *
 * Time Complexity:
 * - Average: O(1)
 * - Worst: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7 // Prime size is important for Quadratic Probing

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
        printf("\n--- Quadratic Probing Hash Table ---\n");
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
    int h = hashFunction(key);

    // Update if key exists
    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;
        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
             printf("Key %d already exists. Updating value.\n", key);
             hashTable[index].value = value;
             return;
        }
        if (hashTable[index].status == EMPTY) break; // Optimization: stop if empty found
    }

    // Insert
    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (hashTable[index].status != OCCUPIED) { // EMPTY or DELETED
            hashTable[index].key = key;
            hashTable[index].value = value;
            hashTable[index].status = OCCUPIED;
            printf("Inserted (%d, %d) at Index %d (i=%d)\n", key, value, index, i);
            return;
        }
    }
    printf("Hash Table is Full or could not find a slot!\n");
}

int search(int key) {
    int h = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (hashTable[index].status == EMPTY) return -1; // Not found

        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {
            return hashTable[index].value;
        }
    }
    return -1;
}

void deleteKey(int key) {
    int h = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

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
