// File: 18_queue_dry_run.c
// Title: Queue Dry Run / Step-by-Step Visualization (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Prints the state of Queue (Front, Rear, Elements) after every operation.
// - Useful for tracing and dry run questions in exams.

#include <stdio.h>

#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void printState(struct Queue *q, const char* op) {
    printf("%-15s | Front: %2d | Rear: %2d | Queue: ", op, q->front, q->rear);
    if (q->front == -1) {
        printf("EMPTY");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
    }
    printf("\n");
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
    
    char op[20];
    sprintf(op, "Enqueue(%d)", value);
    printState(q, op);
}

void dequeue(struct Queue *q) {
    if (q->front == -1) return;
    int val = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    
    char op[20];
    sprintf(op, "Dequeue()");
    printState(q, op);
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("\n--- Queue Dry Run (Step-by-Step) ---\n");
    printState(&q, "Initial");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);
    enqueue(&q, 40);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Becomes empty

    return 0;
}

// Time Complexity:
// - O(n) for display

// Space Complexity:
// - O(1)
