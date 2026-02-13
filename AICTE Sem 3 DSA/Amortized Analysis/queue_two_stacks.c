/*
  File: queue_two_stacks.c
  Title: Queue Implementation using Two Stacks
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements a Queue using Two Stacks (Stack1 and Stack2).
  It demonstrates Amortized O(1) complexity for Dequeue operation.

  Logic:
  - Enqueue: Always push to Stack 1. Complexity: O(1).
  - Dequeue: Pop from Stack 2.
    - If Stack 2 is empty, pop ALL elements from Stack 1 and push them to Stack 2.
    - Then pop from Stack 2.
    - Complexity: Worst Case O(N) (when transferring), but Amortized O(1).

  Amortized Analysis:
  - Each element is pushed to S1 once (Cost 1).
  - Each element is popped from S1 once (Cost 1).
  - Each element is pushed to S2 once (Cost 1).
  - Each element is popped from S2 once (Cost 1).
  - Total cost per element = 4 operations = O(1).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack Definition
typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Queue Definition using Two Stacks
typedef struct {
    Stack s1; // Input stack
    Stack s2; // Output stack
} Queue;

void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Enqueue Operation: O(1)
void enqueue(Queue *q, int val) {
    push(&q->s1, val);
    printf("Enqueued: %d\n", val);
}

// Dequeue Operation: Amortized O(1)
int dequeue(Queue *q) {
    // If both stacks empty, queue is empty
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is Empty\n");
        return -1;
    }

    // If Stack 2 is empty, move elements from Stack 1 to Stack 2
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }

    // Pop from Stack 2
    int val = pop(&q->s2);
    printf("Dequeued: %d\n", val);
    return val;
}

int main() {
    Queue q;
    initQueue(&q);

    printf("=== Queue using Two Stacks (Amortized Analysis) ===\n");

    // Enqueue elements (Cost O(1) each)
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Dequeue elements
    // First dequeue will trigger transfer (Cost O(N))
    dequeue(&q); // 10
    
    // Subsequent dequeues are O(1)
    dequeue(&q); // 20
    
    enqueue(&q, 40);
    
    dequeue(&q); // 30
    dequeue(&q); // 40
    dequeue(&q); // Queue Empty

    printf("\nAnalysis:\n");
    printf("- Enqueue is always O(1).\n");
    printf("- Dequeue is O(N) only when Stack 2 is empty, otherwise O(1).\n");
    printf("- Over a sequence of operations, average cost is O(1).\n");

    return 0;
}

/*
  // Worst Case Time Complexity:
  //   - Enqueue: O(1)
  //   - Dequeue: O(N) (when Stack 2 is empty)
  //
  // Amortized / Expected Time Complexity: O(1) for both Enqueue and Dequeue
  // Space Complexity: O(N)
*/
