// File: 18_delete_node_dll.c
// Title: Delete Node from Doubly Linked List (C)
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

struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node* temp = head;

    // Search for the node
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return head;
    }

    // Deleting head
    if (temp == head) {
        head = head->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    printf("Deleting %d\n", key);
    free(temp);
    return head;
}

int main() {
    // 10 <-> 20 <-> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data = 20;
    head->next->prev = head;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data = 30;
    head->next->next->prev = head->next; head->next->next->next = NULL; head->prev = NULL;

    printf("Original: "); display(head);

    printf("Deleting 20...\n");
    head = deleteNode(head, 20);
    display(head);

    printf("Deleting 10...\n");
    head = deleteNode(head, 10);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
