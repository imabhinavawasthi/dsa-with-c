// File: 09_insert_step_sll.c
// Title: Step-by-Step Insertion Explanation (Dry Run Helper) (C)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    printf("List Content: ");
    while (temp != NULL) {
        printf("[%d|*] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- DRY RUN: INSERT AT BEGINNING ---\n\n");

    struct Node* head = NULL;
    printf("Step 0: Initial State\n");
    printf("HEAD -> NULL\n\n");

    printf("Step 1: User wants to insert 10.\n");
    printf("Step 2: Allocate memory for new node (temp).\n");
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    printf("Step 3: Assign data 10 to temp->data.\n");
    temp->data = 10;
    
    printf("Step 4: Point temp->next to current HEAD (NULL).\n");
    temp->next = head;
    
    printf("Step 5: Update HEAD to point to temp.\n");
    head = temp;
    
    display(head);
    printf("\n");

    printf("--- DRY RUN: INSERT 20 AT BEGINNING ---\n\n");
    
    printf("Step 1: Allocate memory for new node (newNode).\n");
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    printf("Step 2: Assign data 20 to newNode->data.\n");
    newNode->data = 20;

    printf("Step 3: Point newNode->next to current HEAD (node with 10).\n");
    newNode->next = head;

    printf("Step 4: Update HEAD to point to newNode.\n");
    head = newNode;

    display(head);

    return 0;
}

// Time Complexity: O(1) per step
// Space Complexity: O(1)
