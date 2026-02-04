// File: 06_insert_end_sll.c
// Title: Insert Node at End of Singly Linked List (C)
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

struct Node* insertAtEnd(struct Node* head, int newData) {
    // 1. Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL; // It will be the last node, so next is NULL

    // 2. If list is empty, make new node the head
    if (head == NULL) {
        return newNode;
    }

    // 3. Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 4. Link the new node after the last node
    temp->next = newNode;
    
    return head;
}

int main() {
    struct Node* head = NULL;

    printf("Inserting 10 at end...\n");
    head = insertAtEnd(head, 10);
    display(head);

    printf("Inserting 20 at end...\n");
    head = insertAtEnd(head, 20);
    display(head);

    printf("Inserting 30 at end...\n");
    head = insertAtEnd(head, 30);
    display(head);

    return 0;
}

// Time Complexity: O(n) - Need to traverse to finding end
// Space Complexity: O(1)
