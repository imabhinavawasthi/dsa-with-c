/*
 * File: 12_set_intersection.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds the Intersection of two arrays (sets) using Hashing.
 * Intersection: Elements present in BOTH arrays.
 *
 * Logic:
 * 1. Insert all elements of Array 1 into a Hash Table.
 * 2. Iterate through Array 2.
 * 3. Search each element in the Hash Table.
 * 4. If found -> Print it (and optionally remove to avoid duplicates).
 *
 * Time Complexity: O(n + m) where n, m are array sizes.
 * Space Complexity: O(min(n, m)) for the hash table.
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

// Insert unique keys only
void insert(int key) {
    int index = hashFunction(key);
    
    // Check duplicate
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) return;
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search and Delete (to handle printing unique intersection)
// Returns 1 if found and deleted, 0 otherwise
int searchAndDelete(int key) {
    int index = hashFunction(key);
    Node *temp = hashTable[index], *prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            // Found it. Delete it so we don't print it again if Array 2 has duplicates of this key.
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

void findIntersection(int arr1[], int n1, int arr2[], int n2) {
    init();

    // 1. Hash Array 1
    for (int i = 0; i < n1; i++) {
        insert(arr1[i]);
    }

    // 2. Check Array 2 against Hash Table
    printf("Intersection: ");
    int found = 0;
    for (int i = 0; i < n2; i++) {
        if (searchAndDelete(arr2[i])) {
            printf("%d ", arr2[i]);
            found = 1;
        }
    }
    
    if (!found) printf("None");
    printf("\n");
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {30, 40, 60, 70, 80, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    for(int i=0; i<n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i=0; i<n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    findIntersection(arr1, n1, arr2, n2);

    return 0;
}
