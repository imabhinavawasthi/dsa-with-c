/*
 * File: 9_bfs_shortest_path.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds the Shortest Path from a Source to all vertices 
 * in an UNWEIGHTED Graph using BFS.
 * 
 * Concept:
 * BFS explores layer by layer. The first time we reach a node, 
 * it is via the shortest path (minimum edges).
 * 
 * Logic:
 * 1. Maintain a 'dist[]' array initialized to -1 (infinity).
 * 2. Set dist[source] = 0.
 * 3. During BFS, when visiting neighbor 'v' of 'u':
 *      dist[v] = dist[u] + 1
 *      parent[v] = u (to reconstruct path)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
} Graph;

// Queue (Manual)
typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue* q) { q->front = -1; q->rear = -1; }
int isEmpty(Queue* q) { return q->front == -1; }
void enqueue(Queue* q, int val) {
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = val;
}
int dequeue(Queue* q) {
    int item = q->items[q->front];
    if (q->front >= q->rear) q->front = q->rear = -1;
    else q->front++;
    return item;
}

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
        g->dist[i] = -1; // Unvisited
        g->parent[i] = -1;
    }
}

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void BFS_ShortestPath(Graph* g, int startVertex) {
    Queue q;
    initQueue(&q);

    g->dist[startVertex] = 0;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int u = dequeue(&q);

        Node* temp = g->adjLists[u];
        while (temp) {
            int v = temp->dest;
            if (g->dist[v] == -1) { // If not visited
                g->dist[v] = g->dist[u] + 1;
                g->parent[v] = u;
                enqueue(&q, v);
            }
            temp = temp->next;
        }
    }

    printf("\nShortest Distances from Node %d:\n", startVertex);
    for (int i = 0; i < g->numVertices; i++) {
        printf("Node %d: Dist = %d, Parent = %d\n", i, g->dist[i], g->parent[i]);
    }
}

int main() {
    Graph g;
    int v = 6;
    initGraph(&g, v);

    // 0-1, 0-2
    // 1-3
    // 2-4
    // 3-5, 4-5 (5 is reachable from both sides)
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);

    BFS_ShortestPath(&g, 0);

    return 0;
}
