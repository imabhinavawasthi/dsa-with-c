// File: 09_function_call_stack.c
// Title: Function Call Stack Demonstration (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Demonstrates how the system uses a stack (Call Stack) for function calls.
// - When a function is called, a frame is Pushed.
// - When a function returns, a frame is Popped.
// - We use recursion to visualize this.

#include <stdio.h>

void functionC(int n) {
    printf("[PUSH] Inside functionC(%d). Stack frame created.\n", n);
    // Base condition logic or useful work would go here
    printf("[POP]  Exiting functionC(%d). Stack frame destroyed.\n", n);
}

void functionB(int n) {
    printf("[PUSH] Inside functionB(%d). Stack frame created.\n", n);
    functionC(n + 1);
    printf("[POP]  Exiting functionB(%d). Stack frame destroyed.\n", n);
}

void functionA(int n) {
    printf("[PUSH] Inside functionA(%d). Stack frame created.\n", n);
    functionB(n + 1);
    printf("[POP]  Exiting functionA(%d). Stack frame destroyed.\n", n);
}

// Factorial example to show deeper recursion
int factorial(int n) {
    printf("[PUSH] Factorial(%d) called.\n", n);
    if (n <= 1) {
        printf("[BASE] Base case reached at n=%d. Returning 1.\n", n);
        return 1;
    }
    int result = n * factorial(n - 1);
    printf("[POP]  Factorial(%d) returning %d.\n", n, result);
    return result;
}

int main() {
    printf("\n--- Simple Call Stack Demo ---\n");
    printf("[MAIN] Starting Main...\n");
    functionA(1);
    printf("[MAIN] Back in Main.\n");

    printf("\n--- Recursive Factorial Demo ---\n");
    int n = 3;
    printf("Result of Factorial(%d): %d\n", n, factorial(n));

    return 0;
}

// Time Complexity:
// - Dependent on recursion depth. O(n) for factorial.

// Space Complexity:
// - O(n) stack space due to recursion frames.
