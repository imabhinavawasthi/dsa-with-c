// File: 11_delete_end_sll.c
// Title: Delete Node from End of Singly Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    // Case 1: Only one node
    if (head->next == NULL) {
        printf("Deleting node: %d\n", head->data);
        free(head);
        return NULL;
    }

    // Case 2: More than one node
    struct Node* temp = head;
    // Traverse to second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // temp is now second last node
    printf("Deleting node: %d\n", temp->next->data);
    free(temp->next); // Free last node
    temp->next = NULL; // Make second last node as last

    return head;
}

int main() {
    // List: 10 -> 20 -> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data = 30;
    head->next->next->next = NULL;

    printf("Original: "); display(head);

    head = deleteFromEnd(head);
    display(head);

    head = deleteFromEnd(head);
    display(head);

    head = deleteFromEnd(head);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
