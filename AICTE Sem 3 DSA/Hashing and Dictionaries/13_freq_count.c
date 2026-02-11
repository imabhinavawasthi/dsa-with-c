/*
 * File: 13_freq_count.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program counts the frequency of each element in an array using Hashing.
 *
 * Concept:
 * We use a Hash Map (Dictionary) where:
 * - Key: Element from the array
 * - Value: Count of occurrences
 *
 * Steps:
 * 1. Iterate through the array.
 * 2. For each element `x`, search in Hash Map.
 *    - If found: Increment its value (count).
 *    - If not found: Insert `x` with value 1.
 * 3. Traverse the Hash Map to print frequencies.
 *
 * Time Complexity: O(n) average.
 * Space Complexity: O(n) unique elements.
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

void insertOrIncrement(int key) {
    int index = hashFunction(key);
    
    // Check if key exists
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++; // Increment count
            return;
        }
        temp = temp->next;
    }

    // New key: Insert with count = 1
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void printFrequencies() {
    printf("Element  |  Frequency\n");
    printf("---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("   %-5d |     %-5d\n", temp->key, temp->count);
            temp = temp->next;
        }
    }
}

int main() {
    init();

    int arr[] = {10, 20, 10, 30, 10, 20, 40, 50, 40, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        insertOrIncrement(arr[i]);
    }

    printFrequencies();

    return 0;
}
