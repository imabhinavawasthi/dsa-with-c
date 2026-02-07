// File: 11_queue_ll.c
// Title: Queue Implementation using Linked List (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Dynamic Queue implementation.
// - Enqueue at Rear, Dequeue at Front.
// - No overflow unless memory full.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow! Heap memory exhausted.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d\n", front->data);
    
    front = front->next;

    // If queue becomes empty after dequeue
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    printf("\n--- Queue Operations (Linked List) using C ---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Time Complexity:
// - O(1) for insert/delete

// Space Complexity:
// - O(n)
