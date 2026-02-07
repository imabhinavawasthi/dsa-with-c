// File: 05_parenthesis_match.cpp
// Title: Parenthesis Matching using Stack (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Checks for balanced parentheses (), {}, []
// - Uses a Class for Stack.
// - NO STL used.

#include <iostream>
#include <string.h> // For strlen
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }
};

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return true;
    else if (character1 == '{' && character2 == '}') return true;
    else if (character1 == '[' && character2 == ']') return true;
    else return false;
}

bool areParenthesesBalanced(char exp[]) {
    Stack s;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.isEmpty()) {
                return false;
            }
            char popped_char = s.pop();
            if (!isMatchingPair(popped_char, exp[i])) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    char expression[MAX];
    
    cout << "\n--- Parenthesis Matching (C++) ---\n";
    cout << "Enter expression: ";
    cin >> expression;

    if (areParenthesesBalanced(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
