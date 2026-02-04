// File: 19_traverse_dll.c
// Title: Traverse Doubly Linked List Forward and Backward (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseBackward(struct Node* head) {
    if (head == NULL) return;

    // 1. Go to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 2. Traverse backwards using prev
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    // 10 <-> 20 <-> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data = 10;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node)); second->data = 20;
    struct Node* third = (struct Node*)malloc(sizeof(struct Node)); third->data = 30;

    head->prev = NULL; head->next = second;
    second->prev = head; second->next = third;
    third->prev = second; third->next = NULL;

    traverseForward(head);
    traverseBackward(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
