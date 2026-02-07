// File: 07_infix_to_postfix.cpp
// Title: Infix to Postfix Conversion using Stack (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Converts Infix to Postfix.
// - Uses Stack Class for operators.
// - Handles precedence of operators (+, -, *, /, ^).

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char val) {
        if (top == MAX - 1) return;
        arr[++top] = val;
    }

    char pop() {
        if (top == -1) return -1;
        return arr[top--];
    }

    char peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void infixToPostfix(char exp[]) {
    Stack s;
    string result = "";

    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop(); // Remove '('
        }
        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                result += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        result += s.pop();
    }

    cout << "Postfix Expression: " << result << endl;
}

int main() {
    char exp[MAX];
    
    cout << "\n--- Infix to Postfix (C++) ---\n";
    cout << "Enter infix expression: ";
    cin >> exp;

    infixToPostfix(exp);
    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
