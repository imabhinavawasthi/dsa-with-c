/*
  File: queue_two_stacks.cpp
  Title: Queue Implementation using Two Stacks
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements a Queue using Two Stacks (Stack1 and Stack2).
  It demonstrates Amortized O(1) complexity for Dequeue operation.
  
  Note: Custom Stack class is used, no STL.

  Logic:
  - Enqueue: Always push to Stack 1. Complexity: O(1).
  - Dequeue: Pop from Stack 2.
    - If Stack 2 is empty, pop ALL elements from Stack 1 and push them to Stack 2.
    - Then pop from Stack 2.
    - Complexity: Worst Case O(N) (when transferring), but Amortized O(1).
*/

#include <iostream>

using namespace std;

const int MAX = 100;

// Custom Stack Class
class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
};

// Queue Class using Two Stacks
class Queue {
private:
    Stack s1; // Input stack
    Stack s2; // Output stack

public:
    // Enqueue Operation: O(1)
    void enqueue(int val) {
        s1.push(val);
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue Operation: Amortized O(1)
    int dequeue() {
        // If both stacks empty, queue is empty
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        // If Stack 2 is empty, move elements from Stack 1 to Stack 2
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        // Pop from Stack 2
        int val = s2.pop();
        cout << "Dequeued: " << val << endl;
        return val;
    }
};

int main() {
    Queue q;

    cout << "=== Queue using Two Stacks (Amortized Analysis) ===" << endl;

    // Enqueue elements (Cost O(1) each)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Dequeue elements
    // First dequeue will trigger transfer (Cost O(N))
    q.dequeue(); // 10
    
    // Subsequent dequeues are O(1)
    q.dequeue(); // 20
    
    q.enqueue(40);
    
    q.dequeue(); // 30
    q.dequeue(); // 40
    q.dequeue(); // Queue Empty

    cout << endl << "Analysis:" << endl;
    cout << "- Enqueue is always O(1)." << endl;
    cout << "- Dequeue is O(N) only when Stack 2 is empty, otherwise O(1)." << endl;
    cout << "- Over a sequence of operations, average cost is O(1)." << endl;

    return 0;
}

/*
  // Worst Case Time Complexity:
  //   - Enqueue: O(1)
  //   - Dequeue: O(N) (when Stack 2 is empty)
  //
  // Amortized / Expected Time Complexity: O(1) for both Enqueue and Dequeue
  // Space Complexity: O(N)
*/
