/*
 * File: 8_bfs.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Breadth First Search (BFS) using a QUEUE.
 * 
 * BFS Concept:
 * - Level-order traversal.
 * - Explores all neighbors of current vertex before moving deeper.
 * - Uses a FIFO Queue.
 * 
 * Queue Implementation:
 * Manually implemented using an array since <queue> is not available in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// --- Adjacency List ---
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
        g->visited[i] = false;
    }
}

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    
    // For undirected graph
    // newNode = createNode(src);
    // newNode->next = g->adjLists[dest];
    // g->adjLists[dest] = newNode;
}

// --- Queue Implementation ---
typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear)
        q->front = q->rear = -1; // Reset
    else
        q->front++;
    return item;
}

// --- BFS Logic ---
void BFS(Graph* g, int startVertex) {
    Queue q;
    initQueue(&q);

    // 1. Mark and Enqueue start vertex
    g->visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("\nBFS Traversal starting from %d: ", startVertex);

    while (!isEmpty(&q)) {
        // 2. Dequeue
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        // 3. Get all adjacent vertices
        Node* temp = g->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->dest;

            if (!g->visited[adjVertex]) {
                g->visited[adjVertex] = true;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int v = 6;
    initGraph(&g, v);

    // 0 -> 1, 0 -> 2
    // 1 -> 3
    // 2 -> 4
    // 3 -> 5
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 5);

    /*
       0
      / \
     1   2
     |   |
     3   4
     |
     5
     
     BFS Order: 0 1 2 3 4 5
    */

    BFS(&g, 0);

    return 0;
}

// Time: O(V + E)
// Space: O(V)
