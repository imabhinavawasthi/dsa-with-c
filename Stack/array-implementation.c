#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insertion at beginning
void insert_begin(int value) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

// Insertion at end
void insert_end(int value) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}

// Deletion from beginning
void delete_begin() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    last = head;
    while (last->next != head)
        last = last->next;

    temp = head;
    head = head->next;
    last->next = head;
    free(temp);
}

// Deletion from end
void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Traversal
void traverse() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
int main() {
    insert_begin(10);
    insert_begin(20);
    insert_end(30);
    insert_end(40);

    traverse();

    delete_begin();
    traverse();

    delete_end();
    traverse();

    return 0;
}
