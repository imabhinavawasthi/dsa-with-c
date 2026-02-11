/*
 * File: 1_dfs_recursive.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Depth First Search (DFS) using RECURSION.
 * 
 * Graph Representation: Adjacency List.
 * 
 * DFS Concept:
 * 1. Start from a source vertex.
 * 2. Mark it as visited.
 * 3. Recursively visit all its unvisited adjacent vertices.
 * 4. Backtrack when no unvisited neighbors exist.
 * 
 * Role of Recursion:
 * - The system call stack allows us to backtrack automatically.
 * - This simulates the "Stack" data structure used in iterative DFS.
 * 
 * Time Complexity: O(V + E)
 * - V: Number of Vertices (visited once).
 * - E: Number of Edges (each edge visited once/twice).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// --- Adjacency List Implementation ---

// Node for Adjacency List
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Graph Structure
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} Graph;

// Create New Node
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Initialize Graph
void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
        g->visited[i] = false;
    }
}

// Add Edge (Directed for simplicity in traversal demo, allows cycles)
// You can change to undirected by uncommenting the second part
void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    // Uncomment for Undirected Graph
    // newNode = createNode(src);
    // newNode->next = g->adjLists[dest];
    // g->adjLists[dest] = newNode;
}

// --- DFS Recursive Logic ---

void calculateDFS(Graph* g, int vertex) {
    // 1. Mark current node as visited
    g->visited[vertex] = true;
    printf("%d ", vertex);

    // 2. Traverse all adjacent vertices
    Node* temp = g->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->dest;
        
        // 3. If neighbor is not visited, recurse
        if (!g->visited[adjVertex]) {
            calculateDFS(g, adjVertex);
        }
        temp = temp->next;
    }
}

// Wrapper to handle disconnected graphs
void DFS(Graph* g, int startVertex) {
    printf("\nDFS Traversal starting from %d:\n", startVertex);
    
    // Start DFS from the user-specified vertex
    calculateDFS(g, startVertex);

    // Optional: Visit disconnected components
    // for(int i=0; i < g->numVertices; i++) {
    //     if(!g->visited[i]) calculateDFS(g, i);
    // }
    printf("\n");
}

int main() {
    Graph g;
    int v = 6; // 0 to 5
    initGraph(&g, v);

    // Constructing the Graph
    // 0 -> 1, 0 -> 2
    // 1 -> 3, 1 -> 4
    // 2 -> 5 (Simple Tree-like structure)
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4); // Adding cross edge 2->4
    addEdge(&g, 2, 5);

    printf("Graph Structure (Directed):\n");
    printf("0 -> 1, 2\n");
    printf("1 -> 3, 4\n");
    printf("2 -> 4, 5\n");

    DFS(&g, 0);

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V) (Recursion Stack + Visited Array)
