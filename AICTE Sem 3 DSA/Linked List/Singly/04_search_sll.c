// File: 04_search_sll.c
// Title: Search an Element in a Singly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to search for a value
// Returns 1 if found, 0 if not found
int search(struct Node* head, int key) {
    struct Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found at index %d (position %d).\n", key, index, index + 1);
            return 1; // Found
        }
        current = current->next;
        index++;
    }
    printf("Element %d not found in the list.\n", key);
    return 0; // Not found
}

int main() {
    // Creating list: 10 -> 20 -> 30 -> 40 -> NULL
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    struct Node* b = (struct Node*)malloc(sizeof(struct Node));
    struct Node* c = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10; head->next = a;
    a->data = 20; a->next = b;
    b->data = 30; b->next = c;
    c->data = 40; c->next = NULL;

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    search(head, key);

    return 0;
}

// Time Complexity: O(n) - Worst case we check all nodes
// Space Complexity: O(1) - Iterative search uses constant extra space
