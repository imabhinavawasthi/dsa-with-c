// File: 12_expression_tree.cpp
// Purpose: Construct Binary Expression Tree from Postfix Expression
// Author: Abhinav Awasthi

#include <iostream>
#include <cctype> // for isalnum
using namespace std;

#define MAX 100

// Tree Node
class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Manual Stack Class (No STL)
class Stack {
    Node* arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(Node* node) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = node;
    }

    Node* pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return NULL;
        }
        return arr[top--];
    }
    
    // Check if empty (optional helper)
    bool isEmpty() {
        return top == -1;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void inorder(Node* root) {
    if (root == NULL) return;
    
    if (isOperator(root->data)) cout << "(";
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    if (isOperator(root->data)) cout << ")";
}

int main() {
    // E = (a - b) / ((c * d) + e)
    char postfix[] = "ab-cd*e+/";
    Stack s;
    int i = 0;

    cout << "Postfix Expression: " << postfix << endl;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isalnum(ch)) {
            // Operand
            s.push(new Node(ch));
        } else if (isOperator(ch)) {
            // Operator
            Node* right = s.pop();
            Node* left = s.pop();

            Node* opNode = new Node(ch);
            opNode->left = left;
            opNode->right = right;

            s.push(opNode);
        }
        i++;
    }

    Node* root = s.pop();

    cout << "In-order Traversal (Infix form): ";
    inorder(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
