// File: 02_stack_ll.c
// Title: Stack Implementation using Linked List (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Uses a Linked List to implement Stack.
// - Dynamic memory allocation allows stack to grow as needed (no fixed size).
// - Top of stack is the head of the linked list.

#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Initialize top to NULL

// Function to push an element onto the stack
void push(int value) {
    // 1. Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Stack Overflow! Heap memory exhausted.\n");
        return;
    }

    // 2. Assign data
    newNode->data = value;

    // 3. Make new node point to current top
    newNode->next = top;

    // 4. Update top to new node
    top = newNode;

    printf("Pushed %d onto stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    // 1. Store temporary pointer to top
    struct Node* temp = top;

    // 2. Move top to next node
    top = top->next;

    // 3. Print popped value
    printf("Popped element: %d\n", temp->data);

    // 4. Free memory
    free(temp);
}

// Function to peek the top element
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// Function to display the stack elements
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    printf("\n--- Stack Operations (Linked List) using C ---\n");
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
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
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
// - O(n) where n is the number of elements in the stack
