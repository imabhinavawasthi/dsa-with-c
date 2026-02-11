/*
 * File: 14_array_equality.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program checks if two arrays are equal using Hashing.
 * Two arrays are equal if they contain the same elements with the same frequencies.
 * Order does not matter.
 *
 * Logic:
 * 1. Check if sizes are equal. If not -> False.
 * 2. Store elements of Array 1 in a Hash Map (Frequency Count).
 * 3. Traverse Array 2:
 *    - Search element in Hash Map.
 *    - If found and count > 0 -> Decrement count.
 *    - Else -> Return False.
 * 4. Return True.
 *
 * Time Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

// Insert or Increment count
void insert(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search and Decrement count
// Returns 1 if successful, 0 if not found or count is zero
int searchAndDecrement(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            if (temp->count > 0) {
                temp->count--;
                return 1;
            }
            return 0; // Count exhausted (More instances in Array 2 than Array 1)
        }
        temp = temp->next;
    }
    return 0; // Not found
}

int areArraysEqual(int arr1[], int n1, int arr2[], int n2) {
    if (n1 != n2) return 0;
    
    init();

    // Fill Hash Map with Array 1
    for (int i = 0; i < n1; i++) insert(arr1[i]);

    // Check Array 2 against Hash Map
    for (int i = 0; i < n2; i++) {
        if (!searchAndDecrement(arr2[i])) return 0;
    }
    return 1;
}

int main() {
    int arr1[] = {1, 2, 5, 4, 0};
    int arr2[] = {2, 4, 5, 0, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    for(int i=0; i<n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i=0; i<n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    if (areArraysEqual(arr1, n1, arr2, n2)) {
        printf("Result: Arrays are Equal\n");
    } else {
        printf("Result: Arrays are NOT Equal\n");
    }

    return 0;
}
