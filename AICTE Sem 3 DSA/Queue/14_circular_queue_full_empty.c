// File: 14_circular_queue_full_empty.c
// Title: Circular Queue Full/Empty Conditions (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Demonstrates Full and Empty logic.
// - Shows wrapping around behavior (Circular property).

#include <stdio.h>

#define MAX 3

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
        printf("Queue Overflow! Cannot enqueue %d. (Front: %d, Rear: %d)\n", value, q->front, q->rear);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Enqueued: %d. (Front: %d, Rear: %d)\n", value, q->front, q->rear);
}

void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    int val = q->arr[q->front];
    printf("Dequeued: %d. (Front was: %d)\n", val, q->front);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    printf("\n--- Circular Queue Full/Empty Demo ---\n");
    // 1. Fill Queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    // 2. Try to overflow
    printf("Attempting to enqueue 4th element...\n");
    enqueue(&q, 40);

    // 3. Make space
    dequeue(&q); // Remove 10. Front moves to 1.
    
    // 4. Fill again (Wraps around)
    printf("Attempting to enqueue 40 again (Should succeed now due to circularity)...\n");
    enqueue(&q, 40); // Rear wraps to 0.

    // 5. Try to overflow again
    printf("Attempting to enqueue 50...\n");
    enqueue(&q, 50);

    return 0;
}

// Time Complexity:
// - O(1)

// Space Complexity:
// - O(1)
