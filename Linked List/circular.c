#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insertion at beginning
void insert_begin(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

// Insertion at end
void insert_end(int value) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// Deletion from beginning
void delete_begin() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Deletion from end
void delete_end() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Traversal (forward)
void traverse_forward() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Traversal (backward)
void traverse_backward() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward Traversal: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insert_begin(10);
    insert_begin(20);
    insert_end(30);
    insert_end(40);

    traverse_forward();
    traverse_backward();

    delete_begin();
    traverse_forward();

    delete_end();
    traverse_forward();

    return 0;
}
