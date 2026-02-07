// File: 10_queue_array.c
// Title: Queue Implementation using Array (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Queue is FIFO (First In First Out) data structure.
// - Insertion at REAR, Deletion at FRONT.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Initialize front on first element
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    int val = q->arr[q->front];
    q->front++;
    
    // Reset if queue becomes empty to reuse space
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    printf("Dequeued: %d\n", val);
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int choice, value;

    printf("\n--- Queue Operations (Array) using C ---\n");
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
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
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
// - Enqueue: O(1)
// - Dequeue: O(1)
// - Display: O(n)

// Space Complexity:
// - O(n)
