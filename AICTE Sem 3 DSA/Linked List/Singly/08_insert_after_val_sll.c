// File: 08_insert_after_val_sll.c
// Title: Insert Node After a Given Value in Singly Linked List (C)
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

void insertAfterValue(struct Node* head, int targetVal, int newData) {
    struct Node* temp = head;
    
    // Search for the target value
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", targetVal);
        return;
    }

    // Allocate and insert new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    
    // Link
    newNode->next = temp->next;
    temp->next = newNode;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Manually creating list: 10 -> 20 -> 30
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Original List: ");
    display(head);

    printf("Inserting 25 after 20...\n");
    insertAfterValue(head, 20, 25);
    display(head);

    printf("Inserting 99 after 100 (non-existent)...\n");
    insertAfterValue(head, 100, 99);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
