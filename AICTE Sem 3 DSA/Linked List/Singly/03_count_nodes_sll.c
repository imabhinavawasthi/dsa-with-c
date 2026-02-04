// File: 03_count_nodes_sll.c
// Title: Count Number of Nodes in a Singly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;              // Initialize counter
    struct Node* current = head; // Start from head

    while (current != NULL) {
        count++;                // Increment for each node
        current = current->next;// Move to next
    }
    return count;
}

int main() {
    // Hardcoding a list: 10 -> 20 -> 30 -> 40 -> NULL
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* two = (struct Node*)malloc(sizeof(struct Node));
    struct Node* three = (struct Node*)malloc(sizeof(struct Node));
    struct Node* four = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10; head->next = two;
    two->data = 20;  two->next = three;
    three->data = 30; three->next = four;
    four->data = 40;  four->next = NULL;

    printf("Number of nodes in the list: %d\n", countNodes(head));

    return 0;
}

// Time Complexity: O(n) - Linear scan
// Space Complexity: O(1) - Only one counter variable used
