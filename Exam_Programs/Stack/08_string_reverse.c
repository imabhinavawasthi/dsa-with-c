// File: 08_string_reverse.c
// Title: String Reversal using Stack (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Reverses a string using First-In-Last-Out (LIFO) property.
// - Push all chars -> Pop all chars = Reversed.

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, char c) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = c;
}

char pop(struct Stack *s) {
    if (s->top == -1) return '\0';
    return s->arr[s->top--];
}

void reverseString(char* str) {
    struct Stack s;
    initStack(&s);

    // 1. Push all characters to stack
    for (int i = 0; str[i]; i++) {
        push(&s, str[i]);
    }

    // 2. Pop characters back to string or print
    printf("Reversed String: ");
    while (s.top != -1) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main() {
    char str[MAX];
    
    printf("\n--- String Reversal using Stack (C) ---\n");
    printf("Enter a string: ");
    scanf("%s", str); // Does not Read spaces for simplicity

    reverseString(str);
    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
