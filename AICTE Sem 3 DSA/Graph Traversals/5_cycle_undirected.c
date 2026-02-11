/*
 * File: 5_cycle_undirected.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program detects a CYCLE in an UNDIRECTED graph.
 * 
 * Logic Difference from Directed Graph:
 * In Undirected Graph, an edge (u -> v) also implies (v -> u).
 * If we visit v from u, and then v sees u again, that is NOT a cycle (it's the same edge).
 * A cycle exists only if we see a visited neighbor 'w' that is NOT our parent.
 *
 * Implementation:
 * We pass 'parent' in the recursive DFS function.
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

// Undirected Edge (Add both ways)
void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

bool detectCycleUtil(Graph* g, int u, int parent) {
    g->visited[u] = true;

    Node* temp = g->adjLists[u];
    while (temp) {
        int v = temp->dest;

        // If not visited, recurse
        if (!g->visited[v]) {
            if (detectCycleUtil(g, v, u))
                return true;
        }
        // If visited and NOT parent -> Cycle!
        else if (v != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hasCycle(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        if (!g->visited[i]) {
            if (detectCycleUtil(g, i, -1)) // -1 as parent for root
                return true;
        }
    }
    return false;
}

int main() {
    Graph g;
    int v = 5;
    initGraph(&g, v);

    // 0-1, 1-2, 2-3, 3-4 (Line) -> No Cycle
    // Add 4-1 -> Cycle (1-2-3-4-1)
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 4, 1);

    printf("--- Cycle Detection (Undirected) ---\n");
    if (hasCycle(&g))
        printf("Cycle DETECTED.\n");
    else
        printf("No Cycle Found.\n");

    return 0;
}
