// File: 17_insert_end_dll.c
// Title: Insert at End of Doubly Linked List (C)
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

struct Node* insertAtEnd(struct Node* head, int newData) {
    // 1. Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // 2. If list is empty
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    // 3. Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 4. Link
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

int main() {
    struct Node* head = NULL;

    printf("Insert 10 at end...\n");
    head = insertAtEnd(head, 10);
    display(head);

    printf("Insert 20 at end...\n");
    head = insertAtEnd(head, 20);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
