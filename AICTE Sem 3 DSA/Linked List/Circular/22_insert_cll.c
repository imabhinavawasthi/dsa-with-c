// File: 22_insert_cll.c
// Title: Insert Node in Circular Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    if (!head) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

// Insert at beginning
struct Node* insertAtBegin(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    // temp is now last node
    temp->next = newNode;
    newNode->next = head;
    
    // To insert at beginning, change head to newNode
    return newNode; 
}

int main() {
    struct Node* head = NULL;

    printf("Insert 10...\n");
    head = insertAtBegin(head, 10);
    display(head);

    printf("Insert 5...\n");
    head = insertAtBegin(head, 5);
    display(head);

    return 0;
}

// Time Complexity: O(n) - to find tail
// Space Complexity: O(1)
