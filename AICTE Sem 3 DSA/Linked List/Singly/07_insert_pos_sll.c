// File: 07_insert_pos_sll.c
// Title: Insert Node at Specific Position in Singly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAtPosition(struct Node* head, int newData, int position) {
    // 1. Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // 2. Case: Insert at beginning (Position 1)
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    // 3. Traverse to (position - 1)th node
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // 4. Case: Position out of bounds
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode); // Clean up
        return head;   // No change
    }

    // 5. Link new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    struct Node* head = NULL;
    
    // Build initial list: 10 -> 20 -> 30
    // We can rely on insertAtPosition(..., 1) to build it
    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 30, 3);
    
    printf("Initial List: ");
    display(head);

    printf("Inserting 15 at position 2...\n");
    head = insertAtPosition(head, 15, 2);
    display(head);

    printf("Inserting 5 at position 1...\n");
    head = insertAtPosition(head, 5, 1);
    display(head);

    return 0;
}

// Time Complexity: O(n) - Worst case scan to position
// Space Complexity: O(1)
