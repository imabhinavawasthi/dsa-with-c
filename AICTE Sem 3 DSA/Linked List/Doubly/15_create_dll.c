// File: 15_create_dll.c
// Title: Create and Display Doubly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // 1. Allocate memory
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // 2. Assign data and link
    // Head Node
    head->data = 10;
    head->prev = NULL;
    head->next = second;

    // Second Node
    second->data = 20;
    second->prev = head;
    second->next = third;

    // Third Node
    third->data = 30;
    third->prev = second;
    third->next = NULL;

    // 3. Display
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
