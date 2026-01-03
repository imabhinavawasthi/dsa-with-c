#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue (Add)
void enqueue(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

// Dequeue (Delete)
void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Peek
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

// Traversal
void traverse() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    traverse();
    peek();

    dequeue();
    traverse();

    return 0;
}
