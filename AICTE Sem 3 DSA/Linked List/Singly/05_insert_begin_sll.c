// File: 05_insert_begin_sll.c
// Title: Insert Node at Beginning of Singly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to calculate and print list (helper)
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the beginning
// Note: We need to pass address of head pointer because head itself will change
// Alternatively, we can return the new head. Here we return new head for simplicity.
struct Node* insertAtBeginning(struct Node* head, int newData) {
    // 1. Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Assign data
    newNode->data = newData;
    
    // 3. Make next of new node point to current head
    newNode->next = head;
    
    // 4. Update head to point to new node (return it)
    return newNode; 
}

int main() {
    struct Node* head = NULL; // Initially empty list

    printf("Inserting 10 at beginning...\n");
    head = insertAtBeginning(head, 10);
    display(head);

    printf("Inserting 20 at beginning...\n");
    head = insertAtBeginning(head, 20);
    display(head);

    printf("Inserting 30 at beginning...\n");
    head = insertAtBeginning(head, 30);
    display(head);

    return 0;
}

// Time Complexity: O(1) - Constant time insertion
// Space Complexity: O(1) - Constant extra space used
