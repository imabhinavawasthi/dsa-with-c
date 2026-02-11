/*
 * File: 3_graph_properties.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates various Graph Properties using Adjacency Matrix.
 * 
 * Properties Checked:
 * 1. Count Edges: (Sum of degrees / 2) for undirected.
 * 2. Connectivity: Checks if all vertices are reachable from node 0.
 * 3. Tree Check: A graph is a Tree if it is Connected AND has (V-1) edges.
 * 4. Dense vs Sparse: 
 *    - Dense: E is close to V*(V-1)/2
 *    - Sparse: E is much less (close to V).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int v) {
    g->numVertices = v;
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            g->adjMatrix[i][j] = 0;
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Undirected
}

// 1. Count Edges
int countEdges(Graph *g) {
    int count = 0;
    for(int i=0; i<g->numVertices; i++) {
        for(int j=i; j<g->numVertices; j++) { // Loop j from i to avoid double counting
            if(g->adjMatrix[i][j] == 1)
                count++;
        }
    }
    return count;
}

// 2. Connectivity (Simple Reachability Check)
void visit(Graph *g, int v, bool visited[]) {
    visited[v] = true;
    for(int i=0; i<g->numVertices; i++) {
        if(g->adjMatrix[v][i] && !visited[i]) {
            visit(g, i, visited);
        }
    }
}

bool isConnected(Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    
    // Start traversal from vertex 0
    visit(g, 0, visited);

    // If any vertex is not visited, graph is not connected
    for(int i=0; i<g->numVertices; i++) {
        if(!visited[i]) return false;
    }
    return true;
}

// 3. Tree Check
// A connected graph with V nodes and V-1 edges is a Tree.
bool isTree(Graph *g) {
    int E = countEdges(g);
    int V = g->numVertices;

    printf("Edges: %d, Vertices: %d\n", E, V);

    if (isConnected(g) && E == (V - 1))
        return true;
    return false;
}

int main() {
    Graph g;
    int v = 5;
    initGraph(&g, v);

    // Creating a connected graph with 4 edges (Tree)
    // 0-1, 0-2, 0-3, 3-4
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 0, 3);
    addEdge(&g, 3, 4);

    printf("\n--- Graph Properties Check ---\n");
    
    // Analysis
    if (isConnected(&g))
        printf("1. Graph is CONNECTED.\n");
    else
        printf("1. Graph is DISCONNECTED.\n");

    if (isTree(&g))
        printf("2. Graph IS a Tree (Connected & edges = V-1).\n");
    else
        printf("2. Graph is NOT a Tree.\n");
        
    // Check Dense vs Sparse
    int maxEdges = v * (v-1) / 2;
    int currentEdges = countEdges(&g);
    
    printf("3. Density Check:\n");
    printf("   Max Possible Edges: %d\n", maxEdges);
    printf("   Current Edges: %d\n", currentEdges);
    
    if (currentEdges > maxEdges / 2)
        printf("   Verdict: DENSE Graph\n");
    else
        printf("   Verdict: SPARSE Graph\n");

    return 0;
}

// Time Complexity: O(V^2) due to Matrix traversal.
