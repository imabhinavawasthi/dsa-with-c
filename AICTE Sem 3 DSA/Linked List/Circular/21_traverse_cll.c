// File: 21_traverse_cll.c
// Title: Traverse Circular Linked List (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular List: ");
    
    // Do-while loop is best for Circular Linked List
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(HEAD)\n");
}

int main() {
    // 5 -> 10 -> 5
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = tail;
    tail->data = 10;
    tail->next = head;

    traverse(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
