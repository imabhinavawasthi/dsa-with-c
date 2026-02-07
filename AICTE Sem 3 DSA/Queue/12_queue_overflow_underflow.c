// File: 12_queue_overflow_underflow.c
// Title: Queue Overflow and Underflow Demonstration (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Overflow: Enqueuing in full queue.
// - Underflow: Dequeuing from empty queue.
// - Uses small size array.

#include <stdio.h>

#define MAX 3

struct Queue {
    int arr[MAX];
    int front, rear;
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
        printf("[ERROR] Queue Overflow! Cannot enqueue %d. Queue is full.\n", value);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("[ERROR] Queue Underflow! Cannot dequeue. Queue is empty.\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    q->front++;
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("\n--- Queue Overflow Demo ---\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Attempting 4th enqueue...\n");
    enqueue(&q, 40); // Overflow

    printf("\n--- Queue Underflow Demo ---\n");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("Attempting 4th dequeue...\n");
    dequeue(&q); // Underflow

    return 0;
}

// Time Complexity:
// - O(1)

// Space Complexity:
// - O(1)
