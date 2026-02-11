/*
 * File: 4_cycle_directed.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program detects a CYCLE in a DIRECTED graph using DFS.
 * 
 * Logic:
 * A cycle exists if we encounter a "Back Edge" during DFS.
 * A Back Edge points to a node that is currently in the recursion stack.
 *
 * Implementation:
 * We use two arrays:
 * 1. visited[]: Marks if a node has been visited.
 * 2. recStack[]: Marks if a node is in the current recursion stack (ancestor).
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
    bool visited[MAX_VERTICES];
    bool recStack[MAX_VERTICES];
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
        g->recStack[i] = false;
    }
}

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

bool detectCycleUtil(Graph* g, int u) {
    // Mark current node as visited and add to recursion stack
    g->visited[u] = true;
    g->recStack[u] = true;

    Node* temp = g->adjLists[u];
    while (temp) {
        int v = temp->dest;

        // If v is not visited, recurse
        if (!g->visited[v]) {
            if (detectCycleUtil(g, v))
                return true;
        }
        // If v is currently in recursion stack, we found a Back Edge -> Cycle!
        else if (g->recStack[v]) {
            return true;
        }
        temp = temp->next;
    }

    // Remove from recursion stack before backtracking
    g->recStack[u] = false;
    return false;
}

bool hasCycle(Graph* g) {
    // Handle disconnected graph
    for (int i = 0; i < g->numVertices; i++) {
        if (!g->visited[i]) {
            if (detectCycleUtil(g, i))
                return true;
        }
    }
    return false;
}

int main() {
    Graph g;
    int v = 4;
    initGraph(&g, v);

    // Create a cycle: 0 -> 1 -> 2 -> 0
    // And 2 -> 3
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0);
    addEdge(&g, 2, 3);

    printf("--- Cycle Detection (Directed) ---\n");
    if (hasCycle(&g))
        printf("Cycle DETECTED.\n");
    else
        printf("No Cycle Found.\n");

    return 0;
}

// Time: O(V + E)
// Space: O(V)
