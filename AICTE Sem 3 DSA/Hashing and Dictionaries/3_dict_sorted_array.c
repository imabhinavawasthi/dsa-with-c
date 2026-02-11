/*
 * File: 3_dict_sorted_array.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Dictionary ADT using a Sorted Array.
 * The array is always kept sorted by KEY.
 *
 * Advantages:
 * - Search is very fast: O(log n) using Binary Search.
 *
 * Disadvantages:
 * - Insert and Delete are slow: O(n) because of shifting elements.
 *
 * Operations:
 * 1. Insert: Maintain sort order.
 * 2. Search: Use Binary Search.
 * 3. Delete: Find (Binary Search) and remove (Shift).
 *
 * Time Complexity:
 * - Insert: O(n) (Find position + Shift)
 * - Search: O(log n) (Binary Search)
 * - Delete: O(n) (Shift elements)
 *
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int key;
    int value;
} Element;

typedef struct {
    Element items[MAX];
    int size;
} Dictionary;

// Function Prototypes
void init(Dictionary *d);
void insert(Dictionary *d, int key, int value);
int binarySearch(Dictionary *d, int key);
void deleteKey(Dictionary *d, int key);
void display(Dictionary *d);

int main() {
    Dictionary myDict;
    init(&myDict);

    int choice, key, value;

    while (1) {
        printf("\n--- Dictionary ADT (Sorted Array) ---\n");
        printf("1. Insert\n");
        printf("2. Search (Binary Search)\n");
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
                int index = binarySearch(&myDict, key);
                if (index != -1) {
                    printf("Key found at index %d! Value: %d\n", index, myDict.items[index].value);
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

void init(Dictionary *d) {
    d->size = 0;
}

int binarySearch(Dictionary *d, int key) {
    int low = 0, high = d->size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (d->items[mid].key == key)
            return mid;
        else if (d->items[mid].key < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void insert(Dictionary *d, int key, int value) {
    if (d->size == MAX) {
        printf("Dictionary is FULL!\n");
        return;
    }

    // Check if key exists using Binary Search
    int idx = binarySearch(d, key);
    if (idx != -1) {
        printf("Key %d exists. Updating value.\n", key);
        d->items[idx].value = value;
        return;
    }

    // Find position to insert
    int i = d->size - 1;
    while (i >= 0 && d->items[i].key > key) {
        d->items[i + 1] = d->items[i]; // Shift right
        i--;
    }

    d->items[i + 1].key = key;
    d->items[i + 1].value = value;
    d->size++;
    printf("Inserted (%d, %d)\n", key, value);
}

void deleteKey(Dictionary *d, int key) {
    int index = binarySearch(d, key);
    if (index == -1) {
        printf("Key not found!\n");
        return;
    }

    // Shift left to delete
    for (int i = index; i < d->size - 1; i++) {
        d->items[i] = d->items[i + 1];
    }
    d->size--;
    printf("Key %d deleted.\n", key);
}

void display(Dictionary *d) {
    if (d->size == 0) {
        printf("Dictionary is empty.\n");
        return;
    }
    printf("Dictionary Contents (Sorted):\n");
    for (int i = 0; i < d->size; i++) {
        printf("[%d : %d] ", d->items[i].key, d->items[i].value);
    }
    printf("\n");
}

// Time Complexity:
// Insert: O(n) (Shifting)
// Search: O(log n) (Binary Search)
// Delete: O(n) (Shifting)
