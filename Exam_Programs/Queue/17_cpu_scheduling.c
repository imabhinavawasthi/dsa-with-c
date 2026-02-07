// File: 17_cpu_scheduling.c
// Title: Simple CPU Scheduling using Queue (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Simulates First-Come-First-Serve (FCFS) or simple Round Robin.
// - Processes are stored in a Queue.
// - CPU executes them one by one.

#include <stdio.h>
#include <string.h>

#define MAX 5

struct Process {
    char name[10];
    int burstTime;
};

struct Queue {
    struct Process arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void addProcess(struct Queue *q, char* name, int burstTime) {
    if (q->rear == MAX - 1) {
        printf("Ready Queue is Full!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    
    q->rear++;
    strcpy(q->arr[q->rear].name, name);
    q->arr[q->rear].burstTime = burstTime;
    printf("Process %s added to Ready Queue (Burst Time: %d).\n", name, burstTime);
}

void runScheduler(struct Queue *q) {
    printf("\n--- Starting CPU Execution ---\n");
    if (q->front == -1) {
        printf("No processes to schedule.\n");
        return;
    }

    while (q->front != -1 && q->front <= q->rear) {
        struct Process current = q->arr[q->front];
        printf("CPU is executing %s for %d units...\n", current.name, current.burstTime);
        // Simulate execution
        printf("Process %s Completed.\n", current.name);
        
        q->front++; // Remove from queue
    }
    
    // Reset queue
    q->front = -1;
    q->rear = -1;
    printf("All processes finished. CPU Idle.\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("\n--- CPU Scheduling Simulation (FCFS) ---\n");
    
    addProcess(&q, "P1", 10);
    addProcess(&q, "P2", 5);
    addProcess(&q, "P3", 8);

    runScheduler(&q);

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
