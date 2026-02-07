// File: 16_printer_queue.c
// Title: Printer Queue Simulation (C)
// Author: Abhinav Awasthi
// Meaning details:
// - Simulates a printer where documents are lined up.
// - Documents are processed in FIFO order.
// - Uses a Queue to store Job IDs.

#include <stdio.h>
#include <string.h>

#define MAX 5

struct Job {
    int id;
    int pages;
};

struct Queue {
    struct Job arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void addJob(struct Queue *q, int id, int pages) {
    if (q->rear == MAX - 1) {
        printf("Printer Buffer Full! Cannot add Job %d.\n", id);
        return;
    }
    if (q->front == -1) q->front = 0;
    
    q->rear++;
    q->arr[q->rear].id = id;
    q->arr[q->rear].pages = pages;
    printf("Job %d added (%d pages).\n", id, pages);
}

void processJob(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("No jobs to print.\n");
        return;
    }
    struct Job currentJob = q->arr[q->front];
    printf("Printing Job ID: %d ... (%d pages)\n", currentJob.id, currentJob.pages);
    
    q->front++;
}

void displayJobs(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("No pending jobs.\n");
        return;
    }
    printf("Pending Jobs: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("[ID:%d] ", q->arr[i].id);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int choice, id, pages;

    printf("\n--- Printer Queue Simulation (C) ---\n");
    printf("1. Add Job\n");
    printf("2. Process Job\n");
    printf("3. View Pending Jobs\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &id);
                printf("Enter Pages: ");
                scanf("%d", &pages);
                addJob(&q, id, pages);
                break;
            case 2:
                processJob(&q);
                break;
            case 3:
                displayJobs(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Time Complexity:
// - O(1) per job

// Space Complexity:
// - O(n) buffer size
