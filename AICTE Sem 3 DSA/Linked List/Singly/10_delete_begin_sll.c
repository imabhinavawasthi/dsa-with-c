// File: 10_delete_begin_sll.c
// Title: Delete Node from Beginning of Singly Linked List (C)
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

struct Node* deleteFromBeginning(struct Node* head) {
    // 1. Check if list is empty
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    // 2. Save the current head in a temporary pointer
    struct Node* temp = head;

    // 3. Move head to the next node
    head = head->next;

    // 4. Free the memory of the old head
    printf("Deleting node with data: %d\n", temp->data);
    free(temp);

    return head;
}

int main() {
    // Manually creating list: 10 -> 20 -> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    printf("Original List: ");
    display(head);

    head = deleteFromBeginning(head);
    display(head);

    head = deleteFromBeginning(head);
    display(head);

    head = deleteFromBeginning(head);
    display(head);
    
    head = deleteFromBeginning(head); // Attempt on empty list

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
