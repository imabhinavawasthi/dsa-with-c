// File: 13_circular_queue_array.c
// Title: Circular Queue Implementation using Array (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Efficient usage of space using Modulo (%) operator.
// - Reuses empty spaces created by dequeue at the front.
// - Full Condition: (rear + 1) % MAX == front

#include <stdio.h>

#define MAX 5

struct CircularQueue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) // First element
        q->front = 0;
    
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    int val = q->arr[q->front];
    
    // Check if only one element was present
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    printf("Dequeued: %d\n", val);
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[q->rear]); // Print last element
}

int main() {
    struct CircularQueue q;
    initQueue(&q);
    int choice, value;

    printf("\n--- Circular Queue Operations (C) ---\n");
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
// - O(1) for enqueue/dequeue

// Space Complexity:
// - O(n)
