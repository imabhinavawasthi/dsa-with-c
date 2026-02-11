/*
 * File: 7_connected_components.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds Connected Components in an Undirected Graph.
 * 
 * Logic:
 * 1. Iterate through all vertices from 0 to V-1.
 * 2. If a vertex is NOT visited, it marks the start of a NEW component.
 * 3. Start DFS/BFS from that vertex to find current component.
 * 4. Increment component count.
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

// Undirected Graph
void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void dfs(Graph* g, int v) {
    g->visited[v] = true;
    printf("%d ", v);

    Node* temp = g->adjLists[v];
    while (temp) {
        if (!g->visited[temp->dest]) {
            dfs(g, temp->dest);
        }
        temp = temp->next;
    }
}

void findConnectedComponents(Graph* g) {
    int count = 0;
    
    printf("\nConnected Components:\n");
    for (int i = 0; i < g->numVertices; i++) {
        if (!g->visited[i]) {
            count++;
            printf("Component %d: ", count);
            dfs(g, i);
            printf("\n");
        }
    }
    printf("\nTotal Connected Components: %d\n", count);
}

int main() {
    Graph g;
    int v = 5;
    initGraph(&g, v);

    // Component 1: 0-1, 1-2
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);

    // Component 2: 3-4
    addEdge(&g, 3, 4);

    findConnectedComponents(&g);

    return 0;
}
