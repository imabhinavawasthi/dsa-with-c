// File: 08_string_reverse.cpp
// Title: String Reversal using Stack (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Reverses a string using LIFO property.
// - Uses Stack Class.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top == MAX - 1) return;
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void reverseString(char str[]) {
    Stack s;

    // 1. Push all
    for (int i = 0; str[i]; i++) {
        s.push(str[i]);
    }

    // 2. Pop and Print
    cout << "Reversed String: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}

int main() {
    char str[MAX];
    
    cout << "\n--- String Reversal using Stack (C++) ---\n";
    cout << "Enter a string: ";
    cin >> str;

    reverseString(str);
    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
