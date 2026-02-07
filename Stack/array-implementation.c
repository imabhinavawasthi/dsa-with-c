#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

// Traversal
void traverse() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    traverse();
    peek();

    pop();
    traverse();

    return 0;
}
