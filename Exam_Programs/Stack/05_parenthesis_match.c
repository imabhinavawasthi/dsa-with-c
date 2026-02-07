// File: 05_parenthesis_match.c
// Title: Parenthesis Matching using Stack (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Checks if an expression has balanced parentheses.
// - Supports (), {}, []
// - Algorithm:
//   1. Traverse string.
//   2. If opening bracket, Push to stack.
//   3. If closing bracket, Pop and check if it matches the corresponding opening bracket.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Character Stack Structure
struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) return '\0'; // Return null char if empty
    return s->arr[s->top--];
}

// Function to check if brackets match
int isMatching(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

// Function to check balanced parentheses
int isBalanced(char* exp) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(exp); i++) {
        // If opening bracket, push to stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&s, exp[i]);
        }
        // If closing bracket
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // If stack is empty, it means no matching opening bracket
            if (isEmpty(&s)) {
                return 0; 
            }
            
            // Pop the top element
            char poppedChar = pop(&s);

            // Check if popped char matches current closing bracket
            if (!isMatching(poppedChar, exp[i])) {
                return 0;
            }
        }
    }

    // If stack is empty after traversal, it is balanced
    if (isEmpty(&s)) return 1;
    else return 0;
}

int main() {
    char expression[MAX];
    
    printf("\n--- Parenthesis Matching (C) ---\n");
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}

// Time Complexity:
// - O(n) where n is length of expression

// Space Complexity:
// - O(n) for stack in worst case
