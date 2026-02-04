// File: 16_insert_begin_dll.c
// Title: Insert at Beginning of Doubly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int newData) {
    // 1. Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    // 2. If list is empty, return new node as head
    if (head == NULL) {
        return newNode;
    }

    // 3. Link new node
    newNode->next = head;
    head->prev = newNode; 

    // 4. Return new head
    return newNode;
}

int main() {
    struct Node* head = NULL;

    printf("Insert 10...\n");
    head = insertAtBeginning(head, 10);
    display(head);

    printf("Insert 5...\n");
    head = insertAtBeginning(head, 5);
    display(head);

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
