/*
 * File: 1_dict_array.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Dictionary ADT using a static Array.
 *
 * Dictionary ADT:
 * A Dictionary is an abstract data type that stores key-value pairs.
 * It supports three primary operations:
 * 1. Insert(key, value): Add a new pair to the dictionary.
 * 2. Search(key): Find the value associated with a key.
 * 3. Delete(key): Remove the pair associated with a key.
 *
 * In this implementation:
 * - We use a struct 'Element' to store key and value.
 * - An array 'dict[]' stores these elements.
 * - 'size' tracks the current number of elements.
 *
 * Time Complexity:
 * - Insert: O(1) (We insert at the end) - O(n) if we check for duplicates first.
 *           Here we assume unique keys or check O(n).
 *           Let's implement simple append O(1) but for strict dictionary we usually check existence O(n).
 *           We will check for duplicates to maintain dictionary property -> O(n).
 * - Search: O(n) (Linear Search)
 * - Delete: O(n) (Find element and shift remaining elements)
 *
 * Space Complexity: O(n) for the array.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a dictionary element
typedef struct {
    int key;
    int value;
} Element;

// Dictionary structure
typedef struct {
    Element items[MAX];
    int size;
} Dictionary;

// Function Prototypes
void init(Dictionary *d);
void insert(Dictionary *d, int key, int value);
int search(Dictionary *d, int key);
void deleteKey(Dictionary *d, int key);
void display(Dictionary *d);

int main() {
    Dictionary myDict;
    init(&myDict);

    int choice, key, value;

    while (1) {
        printf("\n--- Dictionary ADT (Array Implementation) ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(&myDict, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int val = search(&myDict, key);
                if (val != -1) {
                    printf("Key found! Value: %d\n", val);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(&myDict, key);
                break;
            case 4:
                display(&myDict);
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

// Initialize dictionary
void init(Dictionary *d) {
    d->size = 0;
}

// Insert an element
void insert(Dictionary *d, int key, int value) {
    // Check if dictionary is full
    if (d->size == MAX) {
        printf("Dictionary is FULL!\n");
        return;
    }

    // Check for duplicate key
    for (int i = 0; i < d->size; i++) {
        if (d->items[i].key == key) {
            printf("Key %d already exists. Updating value.\n", key);
            d->items[i].value = value;
            return;
        }
    }

    // Insert at end
    d->items[d->size].key = key;
    d->items[d->size].value = value;
    d->size++;
    printf("Inserted (%d, %d)\n", key, value);
}

// Search for a key and return its value
int search(Dictionary *d, int key) {
    for (int i = 0; i < d->size; i++) {
        if (d->items[i].key == key) {
            return d->items[i].value;
        }
    }
    return -1; // Return -1 indicating not found (assuming positive values)
}

// Delete an element by key
void deleteKey(Dictionary *d, int key) {
    int i, index = -1;

    // Find the key
    for (i = 0; i < d->size; i++) {
        if (d->items[i].key == key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Key not found!\n");
        return;
    }

    // Shift elements to fill the gap (unless it's the last element)
    for (i = index; i < d->size - 1; i++) {
        d->items[i] = d->items[i + 1];
    }

    d->size--;
    printf("Key %d deleted.\n", key);
}

// Display all elements
void display(Dictionary *d) {
    if (d->size == 0) {
        printf("Dictionary is empty.\n");
        return;
    }
    printf("Dictionary Contents:\n");
    for (int i = 0; i < d->size; i++) {
        printf("[%d : %d] ", d->items[i].key, d->items[i].value);
    }
    printf("\n");
}

// Time Complexity (Average & Worst Case):
// Insert: O(n) (Checking for duplicates)
// Search: O(n) (Linear Search)
// Delete: O(n) (Shifting elements)
//
// Space Complexity: O(n) (For array storage)
