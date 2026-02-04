// File: 13_delete_val_sll.c
// Title: Delete Node with Specific Value in Singly Linked List (C)
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

struct Node* deleteByValue(struct Node* head, int key) {
    if (head == NULL) return NULL;

    // If head holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleting value: %d\n", key);
        free(temp);
        return head;
    }

    // Search for key
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }

    // Unlink
    printf("Deleting value: %d\n", key);
    prev->next = temp->next;
    free(temp);
    
    return head;
}

int main() {
    // 10 -> 20 -> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data = 30;
    head->next->next->next = NULL;

    display(head);

    head = deleteByValue(head, 20);
    display(head);

    head = deleteByValue(head, 10);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
