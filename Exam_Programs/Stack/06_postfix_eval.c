// File: 06_postfix_eval.c
// Title: Postfix Expression Evaluation using Stack (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Evaluates a postfix expression (e.g., "53+82-*").
// - Operands are pushed to stack.
// - Operators pop two elements, compute, and push back result.
// - Note: Supports single digit operands for simplicity.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

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

int pop(struct Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

int evaluatePostfix(char* exp) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; exp[i]; i++) {
        // If character is digit, push to stack
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0'); // Convert char '5' to int 5
        }
        // If character is operator, pop two elements
        else {
            int val1 = pop(&s);
            int val2 = pop(&s);

            switch (exp[i]) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2 / val1); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX];
    
    printf("\n--- Postfix Evaluation (C) ---\n");
    printf("Enter postfix expression (e.g., 231*+9-): ");
    scanf("%s", exp);

    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n) for stack
