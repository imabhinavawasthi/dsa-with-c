// File: 01_stack_array.c
// Title: Stack Implementation using Array (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Stack is a LIFO (Last In First Out) data structure.
// - Operations are performed at one end called 'TOP'.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Structure definition for Stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;  // Stack is initially empty
}

// Function to check if stack is full
int isFull(struct Stack *s) {
    if (s->top == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->top++;              // Increment top
    s->arr[s->top] = value; // Insert value at top
    printf("Pushed %d onto stack.\n", value);
}

// Function to pop an element from the stack
void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    int poppedValue = s->arr[s->top];
    s->top--;              // Decrement top
    printf("Popped element: %d\n", poppedValue);
}

// Function to peek the top element
void peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", s->arr[s->top]);
}

// Function to display the stack elements
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    struct Stack stack;
    initStack(&stack);
    int choice, value;

    printf("\n--- Stack Operations (Array) using C ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Time Complexity:
// - Push: O(1)
// - Pop: O(1)
// - Peek: O(1)
// - Display: O(n)

// Space Complexity:
// - O(n) where n is the size of the stack (static array usage)
