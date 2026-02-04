// File: 14_delete_step_sll.c
// Title: Step-by-Step Deletion Explanation (Dry Run Helper) (C)
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
    printf("List Content: ");
    while (temp != NULL) {
        printf("[%d|*] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- DRY RUN: DELETE FROM BEGINNING ---\n\n");

    // Create a list: 10 -> 20 -> NULL
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = NULL;

    printf("Step 0: Initial State\n");
    display(head);
    printf("\n");

    printf("Step 1: Check if list is empty (head == NULL).\n");
    printf("Result: List is not empty.\n");

    printf("Step 2: Save current HEAD in a temporary variable (temp).\n");
    struct Node* temp = head;
    printf("temp points to node with data %d\n", temp->data);

    printf("Step 3: Move HEAD to next node (head = head->next).\n");
    head = head->next;
    printf("New HEAD is node with data %d\n", head->data);

    printf("Step 4: Free memory pointed to by temp.\n");
    free(temp);
    printf("Memory freed.\n");

    printf("Step 5: Final State\n");
    display(head);

    return 0;
}

// Time Complexity: O(1) per step
// Space Complexity: O(1)
