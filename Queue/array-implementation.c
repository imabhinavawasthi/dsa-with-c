#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


bool isEmpty() {
    return front == -1 || front > rear;
}

bool isFull() {
    return rear == MAX - 1;
}

// Enqueue (Add)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

// Dequeue (Delete)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
}

// Peek
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Traversal
void traverse() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    traverse();
    peek();

    dequeue();
    traverse();

    return 0;
}
