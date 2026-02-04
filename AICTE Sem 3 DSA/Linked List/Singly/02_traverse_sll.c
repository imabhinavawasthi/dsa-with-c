// File: 02_traverse_sll.c
// Title: Traverse a Singly Linked List (C)
// Author: Abhinav Awasthi
// Description: This program creates a linked list and traverses it, printing data of each node.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the list
void traverse(struct Node* head) {
    // 1. Check if list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    
    // 2. Iterate until current is NULL
    printf("Traversing List: ");
    while (current != NULL) {
        printf("%d ", current->data); // Process the current node
        current = current->next;      // Move to the next node
    }
    printf("\n");
}

int main() {
    // Create nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Initialize nodes
    head->data = 100;
    head->next = second;

    second->data = 200;
    second->next = third;

    third->data = 300;
    third->next = NULL;

    // Traverse the list
    traverse(head);

    return 0; // OS will free memory heavily, but strictly we should free
}

// Time Complexity: O(n) - We visit every node once.
// Space Complexity: O(1) - No extra space used for traversal.
