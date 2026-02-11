/*
 * File: 1_graph_adj_matrix.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Graph using an Adjacency Matrix.
 * 
 * What is a Graph ADT?
 * A Graph is a non-linear data structure consisting of vertices (nodes) and edges (connections).
 * 
 * Adjacency Matrix Representation:
 * A 2D array adj[V][V] where:
 * - adj[i][j] = 1 if there is an edge from vertex i to vertex j.
 * - adj[i][j] = 0 otherwise.
 * 
 * Space Complexity: O(V^2)
 * - Good for Dense Graphs (many edges).
 * - Waste of space for Sparse Graphs (few edges).
 * 
 * Operations:
 * 1. Create Graph (Initialize Matrix)
 * 2. Add Edge (Directed / Undirected)
 * 3. Delete Edge
 * 4. Display Matrix
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph Structure
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int isDirected; // 1 for Directed, 0 for Undirected
} Graph;

// Initialize Graph
void initGraph(Graph *g, int vertices, int directed) {
    g->numVertices = vertices;
    g->isDirected = directed;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add Edge
void addEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid Vertex!\n");
        return;
    }

    g->adjMatrix[src][dest] = 1;

    // If undirected, add edge from dest to src as well
    if (!g->isDirected) {
        g->adjMatrix[dest][src] = 1;
    }
    printf("Edge added: %d -> %d\n", src, dest);
}

// Delete Edge
void removeEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid Vertex!\n");
        return;
    }

    g->adjMatrix[src][dest] = 0;

    if (!g->isDirected) {
        g->adjMatrix[dest][src] = 0;
    }
    printf("Edge removed: %d -> %d\n", src, dest);
}

// Check if edge exists
int hasEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices) return 0;
    return g->adjMatrix[src][dest];
}

// Display Matrix
void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->numVertices; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int v, choice, type, src, dest;

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &v);

    printf("Enter Graph Type (0 for Undirected, 1 for Directed): ");
    scanf("%d", &type);

    initGraph(&g, v, type);

    while (1) {
        printf("\n--- Graph Operations (Adjacency Matrix) ---\n");
        printf("1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Check Edge\n");
        printf("4. Display Matrix\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Source and Destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(&g, src, dest);
                break;
            case 2:
                printf("Enter Source and Destination: ");
                scanf("%d %d", &src, &dest);
                removeEdge(&g, src, dest);
                break;
            case 3:
                printf("Enter Source and Destination: ");
                scanf("%d %d", &src, &dest);
                if (hasEdge(&g, src, dest))
                    printf("Edge Exists.\n");
                else
                    printf("Edge DOES NOT Exist.\n");
                break;
            case 4:
                displayGraph(&g);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

// Time Complexity:
// - Add/Remove Edge: O(1)
// - Check Edge: O(1)
// - Space Complexity: O(V^2) (Very expensive for large graphs)
