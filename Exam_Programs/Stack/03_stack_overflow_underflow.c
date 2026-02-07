// File: 03_stack_overflow_underflow.c
// Title: Stack Overflow and Underflow Demonstration (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Stack Overflow: Trying to push into a full stack.
// - Stack Underflow: Trying to pop from an empty stack.
// - We use a small stack size (3) to easily demonstrate these conditions.

#include <stdio.h>
#include <stdlib.h>

#define MAX 3 // Small size for demonstration

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("[ERROR] Stack Overflow! Cannot push %d. Stack is full (Limit: %d).\n", value, MAX);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
    printf("Pushed: %d\n", value);
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("[ERROR] Stack Underflow! Cannot pop. Stack is already empty.\n");
        return;
    }
    printf("Popped: %d\n", s->arr[s->top]);
    s->top--;
}

int main() {
    struct Stack s;
    initStack(&s);

    printf("\n--- Stack Overflow Demonstration ---\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    // This next push will cause Overflow
    printf("Attempting to push 4th element...\n");
    push(&s, 40); 

    printf("\n--- Stack Underflow Demonstration ---\n");
    pop(&s);
    pop(&s);
    pop(&s);
    // This next pop will cause Underflow
    printf("Attempting to pop from empty stack...\n");
    pop(&s);

    return 0;
}

// Time Complexity:
// - All operations are O(1)

// Space Complexity:
// - O(1) considering fixed small size for demo
