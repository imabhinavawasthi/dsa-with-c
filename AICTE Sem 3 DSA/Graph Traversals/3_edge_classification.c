/*
 * File: 3_edge_classification.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program classifies edges in a DIRECTED graph using DFS.
 * 
 * Classification Logic:
 * We use Discovery Time (startTime) and Finish Time (endTime) for each vertex.
 * 
 * Edge (u -> v):
 * 1. Tree Edge: v is visited for the first time during DFS traversal of u.
 * 2. Back Edge: v is an ancestor of u (v is currently in recursion stack). 
 *    - Condition: v is visited AND v is still processing (in stack).
 *    - Indicates a CYCLE.
 * 3. Forward Edge: v is a descendant of u, but already visited.
 *    - Condition: v visited, not in stack, startTime[u] < startTime[v].
 * 4. Cross Edge: v is neither ancestor nor descendant.
 *    - Condition: v visited, not in stack, startTime[u] > startTime[v].
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
    int startTime[MAX_VERTICES];
    int endTime[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int time; // Global timer
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    g->time = 0;
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
        g->startTime[i] = 0;
        g->endTime[i] = 0;
        g->visited[i] = false;
    }
}

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

void DFS_Classify(Graph* g, int u) {
    g->visited[u] = true;
    g->startTime[u] = ++(g->time); // Discovery Time

    Node* temp = g->adjLists[u];
    while (temp) {
        int v = temp->dest;

        if (!g->visited[v]) {
            printf("Edge (%d -> %d): TREE EDGE\n", u, v);
            DFS_Classify(g, v);
        } else {
            // Node v is already visited. Check Edge Type.
            // If v has no finish time yet, it means v is an ancestor (Back Edge).
            if (g->endTime[v] == 0) {
                printf("Edge (%d -> %d): BACK EDGE (Cycle Detected!)\n", u, v);
            }
            // If v is finished, check start times
            else if (g->startTime[u] < g->startTime[v]) {
                printf("Edge (%d -> %d): FORWARD EDGE\n", u, v);
            } 
            else {
                printf("Edge (%d -> %d): CROSS EDGE\n", u, v);
            }
        }
        temp = temp->next;
    }

    g->endTime[u] = ++(g->time); // Finish Time
}

int main() {
    Graph g;
    int v = 5;
    initGraph(&g, v);

    // 0 -> 1 (Tree)
    // 0 -> 2 (Tree)
    // 1 -> 2 (Forward/Cross depending on traversal order)
    // 2 -> 0 (Back)
    // 2 -> 3 (Tree)
    // 3 -> 3 (Back - Self Loop)
    // 4 -> 2 (Cross)
    
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0); 
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 3);
    addEdge(&g, 4, 2);

    printf("--- Edge Classification ---\n");
    // Run DFS for all components to classify all edges
    for(int i=0; i<v; i++) {
        if(!g.visited[i]) {
            DFS_Classify(&g, i);
        }
    }

    return 0;
}

// Time: O(V + E)
// Space: O(V)
