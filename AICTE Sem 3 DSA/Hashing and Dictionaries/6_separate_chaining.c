/*
 * File: 6_separate_chaining.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table with Separate Chaining for collision resolution.
 *
 * Concept:
 * - The Hash Table is an array of Linked Lists (Chains).
 * - When a collision occurs (two keys map to same index), the new key is added to the linked list at that index.
 *
 * Advantages:
 * - Simple to implement.
 * - Hash table never fills up (we can always add more nodes).
 * - Less sensitive to hashing function quality compared to Probing.
 *
 * Disadvantages:
 * - Uses extra memory for pointers.
 * - Cache performance is poor due to non-contiguous nodes.
 *
 * Operations:
 * 1. Insert: Hash key -> Insert into list.
 * 2. Search: Hash key -> Search list.
 * 3. Delete: Hash key -> Delete from list.
 *
 * Time Complexity:
 * - Average: O(1 + alpha) where alpha = n/m (Load Factor).
 * - Worst: O(n) (If all keys map to same index).
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7  // Small prime size to demonstrate collisions easily

// Node structure for Separate Chaining
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Hash Table is an array of Node pointers
Node* hashTable[SIZE];

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
        printf("\n--- Separate Chaining Hash Table ---\n");
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
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);

    // Check if key exists to update value
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key %d exists at Index %d. Updating value.\n", key, index);
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    
    // Insert at head of the list (O(1))
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    
    printf("Inserted (%d, %d) at Index %d\n", key, value, index);
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Not found
}

void deleteKey(int key) {
    int index = hashFunction(key);
    Node *temp = hashTable[index], *prev = NULL;

    // Case 1: Head node holds the key
    if (temp != NULL && temp->key == key) {
        hashTable[index] = temp->next;
        free(temp);
        printf("Key %d deleted from Index %d.\n", key, index);
        return;
    }

    // Case 2: Search in the list
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // Unlink
    prev->next = temp->next;
    free(temp);
    printf("Key %d deleted from Index %d.\n", key, index);
}

void display() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        if (temp == NULL) {
            printf("NULL");
        } else {
            while (temp != NULL) {
                printf("[%d : %d] -> ", temp->key, temp->value);
                temp = temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

// Time Complexity (Average & Worst Case):
// Insert: O(1 + alpha) -> O(1) on average.
// Search: O(1 + alpha) -> O(1) on average.
// Delete: O(1 + alpha) -> O(1) on average.
// Worst case O(n) if all keys hash to same index.
// Space Complexity: O(m + n) (Table size + Nodes)
