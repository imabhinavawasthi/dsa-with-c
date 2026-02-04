// File: 12_delete_pos_sll.c
// Title: Delete Node at Specific Position in Singly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;

    // Case 1: Delete head (Position 1)
    if (position == 1) {
        head = head->next;
        printf("Deleting: %d\n", temp->data);
        free(temp);
        return head;
    }

    // Case 2: Traverse to previous node (position - 1)
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d out of bounds.\n", position);
        return head;
    }

    struct Node* toDelete = temp->next;
    printf("Deleting: %d\n", toDelete->data);
    
    // Unlink the node
    temp->next = toDelete->next;
    
    // Free memory
    free(toDelete);

    return head;
}

int main() {
    // List: 10 -> 20 -> 30 -> 40
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data = 30;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    printf("Original: "); display(head);

    printf("Deleting node at position 2...\n");
    head = deleteAtPosition(head, 2);
    display(head);

    printf("Deleting node at position 1...\n");
    head = deleteAtPosition(head, 1);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
