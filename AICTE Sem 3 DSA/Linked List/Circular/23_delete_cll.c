// File: 23_delete_cll.c
// Title: Delete Node from Circular Linked List (C)
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

struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node *curr = head, *prev = NULL;

    // Check if head is the node to delete
    if (head->data == key) {
        // Find last node
        while (curr->next != head) {
            curr = curr->next;
        }
        
        // If only one node
        if (curr == head) {
            free(head);
            return NULL;
        }

        // More than one node
        curr->next = head->next;
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head; 
    }

    // If node is not head
    prev = head;
    curr = head->next;
    
    while (curr != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        printf("Node %d not found.\n", key);
        return head;
    }

    prev->next = curr->next;
    free(curr);
    return head;
}

int main() {
    // 10 -> 20 -> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = head;

    printf("Original: "); display(head);

    printf("Delete 10 (head)...\n");
    head = deleteNode(head, 10);
    display(head);

    printf("Delete 30...\n");
    head = deleteNode(head, 30);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
