// File: 06_postfix_eval.cpp
// Title: Postfix Expression Evaluation using Stack (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Evaluates postfix (Reverse Polish Notation) expressions.
// - Uses a Stack Class to store integer operands.
// - Supports single digit inputs.

#include <iostream>
#include <cctype> // for isdigit
#include <cstring> // for strlen
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) return;
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) return -1;
        return arr[top--];
    }
};

int evaluatePostfix(char exp[]) {
    Stack s;

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        else {
            int val1 = s.pop();
            int val2 = s.pop();

            switch (exp[i]) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
            }
        }
    }
    return s.pop();
}

int main() {
    char exp[MAX];
    
    cout << "\n--- Postfix Evaluation (C++) ---\n";
    cout << "Enter postfix expression (e.g., 231*+9-): ";
    cin >> exp;

    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
