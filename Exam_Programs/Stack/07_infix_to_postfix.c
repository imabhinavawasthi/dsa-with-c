// File: 07_infix_to_postfix.c
// Title: Infix to Postfix Conversion using Stack (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Converts Infix expression (A+B) to Postfix expression (AB+).
// - Uses stack to handle operator precedence.
// - Algorithm: Shunting Yard Algorithm (Simplified).

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, char val) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = val;
}

char pop(struct Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

char peek(struct Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void infixToPostfix(char* exp) {
    struct Stack s;
    initStack(&s);
    char result[MAX];
    int k = 0;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];

        // If operand, add to result
        if (isalnum(c)) {
            result[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(&s, c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                result[k++] = pop(&s);
            }
            pop(&s); // Pop '('
        }
        // If operator
        else {
            while (s.top != -1 && precedence(c) <= precedence(peek(&s))) {
                result[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    // Pop remaining operators
    while (s.top != -1) {
        result[k++] = pop(&s);
    }
    result[k] = '\0'; // Null terminate result string

    printf("Postfix Expression: %s\n", result);
}

int main() {
    char exp[MAX];
    
    printf("\n--- Infix to Postfix (C) ---\n");
    printf("Enter infix expression (e.g., A+B*C): ");
    scanf("%s", exp);

    infixToPostfix(exp);
    return 0;
}

// Time Complexity:
// - O(n) where n is length of expression

// Space Complexity:
// - O(n) for stack and result string
