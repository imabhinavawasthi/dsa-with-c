/*
 * File: 11_find_duplicates.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds duplicate elements in an array using Hashing.
 *
 * Concept:
 * We use a Hash Table to keep track of elements we have seen so far.
 * As we iterate through the array:
 * 1. Check if element exists in Hash Table.
 * 2. If YES -> It is a duplicate. Print it.
 * 3. If NO -> Insert it into Hash Table.
 *
 * Time Complexity: O(n) on average.
 * Space Complexity: O(n) for the hash table.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct Node {
    int key;
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

// Returns 1 if key exists, 0 otherwise
int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void findDuplicates(int arr[], int n) {
    printf("Duplicate Elements: ");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (search(arr[i])) {
            printf("%d ", arr[i]);
            found = 1;
        } else {
            insert(arr[i]);
        }
    }
    if (!found) printf("None");
    printf("\n");
}

int main() {
    init();
    
    int arr[] = {10, 20, 10, 30, 40, 20, 50, 60, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    findDuplicates(arr, n);

    return 0;
}
