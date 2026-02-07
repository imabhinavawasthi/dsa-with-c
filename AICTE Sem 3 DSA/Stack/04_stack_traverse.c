// File: 04_stack_traverse.c
// Title: Stack Traversal / Display (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Demonstrates how to iterate through stack elements.
// - Standard traversal is Top to Bottom (LIFO order).

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = value;
}

// 1. Standard Traversal: Top to Bottom
void traverseTopToBottom(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top -> Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// 2. Recursive Traversal: Bottom to Top (Visualizing stack content physically)
// NOTE: This is for display purposes, stack access is usually restricted to Top.
void traverseBottomToTop(struct Stack *s) {
     if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Bottom -> Top): ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    /*
      Stack visualization:
      50 <- Top
      40
      30
      20
      10 <- Bottom
    */

    printf("\n--- Stack Traversal Demonstration ---\n");
    
    // Standard LIFO view
    traverseTopToBottom(&s); 

    // Physical memory view
    traverseBottomToTop(&s);

    return 0;
}

// Time Complexity:
// - Traversal: O(n)

// Space Complexity:
// - O(1) for iterative traversal
