// File: 15_circular_queue_traverse.c
// Title: Traverse Circular Queue (C)
// Author: Abhinav Awasthi
// Meaning details:
// - How to iterate through a circular queue.
// - Starts at Front, moves circularly using (i+1)%MAX until Rear.

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

void enqueue(struct CircularQueue *q, int value) {
    if ((q->rear + 1) % MAX == q->front) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

void traverse(struct CircularQueue *q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue Elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[q->rear]); // Print the last element
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    // 1. Fill Queue partially
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // 2. Traverse
    printf("\n--- Initial Traversal ---\n");
    traverse(&q);

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(1)
