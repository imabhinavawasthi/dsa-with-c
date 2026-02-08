// File: 12_expression_tree.c
// Purpose: Construct Binary Expression Tree from Postfix Expression
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isalnum

#define MAX 100

/*
 * Expression Tree Logic:
 * Input: Postfix Expression `ab-cd*e+/`
 * Algorithm:
 * 1. Scan the postfix expression.
 * 2. If Operand: Create Node, Push to Stack.
 * 3. If Operator: 
 *    - Create Node(operator)
 *    - Pop two nodes from stack (Right then Left)
 *    - Make them children of Operator Node
 *    - Push Operator Node back to Stack.
 */

// Tree Node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Stack to hold Node pointers
struct Node* stack[MAX];
int top = -1;

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(struct Node* node) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = node;
}

struct Node* pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--];
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// In-order Traversal (produces Infix expression)
void inorder(struct Node* root) {
    if (root == NULL) return;
    // Print parenthesis for operator nodes to preserve precedence
    if (isOperator(root->data)) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (isOperator(root->data)) printf(")");
}

int main() {
    char postfix[] = "ab-cd*e+/";
    /*
     * Expression: (a - b) / ((c * d) + e)
     * Postfix: ab-cd*e+/
     */
    
    int i = 0;
    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            // Operand: Push new node
            push(createNode(symbol));
        } else if (isOperator(symbol)) {
            // Operator: Pop two nodes
            struct Node* right = pop();
            struct Node* left = pop();

            // Create operator node
            struct Node* opNode = createNode(symbol);
            opNode->left = left;
            opNode->right = right;

            // Push back
            push(opNode);
        }
        i++;
    }

    struct Node* root = pop();

    printf("Postfix Expression: %s\n", postfix);
    printf("Constructed Expression Tree (In-order / Infix): ");
    inorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N) where N is length of expression
// Space Complexity: O(N) for stack
