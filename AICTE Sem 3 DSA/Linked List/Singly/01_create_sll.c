// File: 01_create_sll.c
// Title: Create and Display a Singly Linked List (C)
// Author: Abhinav Awasthi
// Description: This program demonstrates how to create a simple singly linked list with hardcoded nodes and display it.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;           // Data part of the node
    struct Node* next;  // Pointer to the next node
};

// Function to print the linked list
void displayList(struct Node* head) {
    struct Node* temp = head; // Start traversal from head
    
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print data
        temp = temp->next;            // Move to next node
    }
    printf("NULL\n");
}

int main() {
    // 1. Allocate memory for nodes
    // We are creating 3 nodes for this example
    struct Node* first  = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*)malloc(sizeof(struct Node));

    // 2. Assign data and link nodes
    
    // First Node
    first->data = 10;
    first->next = second; // Link first node to second

    // Second Node
    second->data = 20;
    second->next = third; // Link second node to third

    // Third Node
    third->data = 30;
    third->next = NULL;   // Last node points to NULL

    // Head points to the first node
    struct Node* head = first;

    // 3. Display the list
    displayList(head);

    // Free memory (Good practice, though often skipped in simple exam snippets, useful to know)
    free(first);
    free(second);
    free(third);

    return 0;
}

// Time Complexity: O(n) for display (where n is number of nodes)
// Space Complexity: O(1) auxiliary space (nodes are part of input data structure)
