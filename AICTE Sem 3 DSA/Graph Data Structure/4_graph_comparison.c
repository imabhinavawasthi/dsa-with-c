/*
 * File: 4_graph_comparison.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program compares Adjacency Matrix and Adjacency List representations.
 * 
 * We construct the SAME graph using both methods and compare:
 * 1. Memory Usage (Theoretical & Calculated)
 * 2. Suitability (Dense vs Sparse)
 * 
 * Graph Used: 5 Vertices, 4 Edges (Sparse)
 * 0-1, 0-2, 1-3, 3-4
 */

#include <stdio.h>
#include <stdlib.h>

#define V 5

// --- 1. Adjacency Matrix ---
typedef struct {
    int mat[V][V];
} GraphMatrix;

void initMatrix(GraphMatrix *g) {
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            g->mat[i][j] = 0;
}

void addEdgeMatrix(GraphMatrix *g, int src, int dest) {
    g->mat[src][dest] = 1;
    g->mat[dest][src] = 1;
}

// --- 2. Adjacency List ---
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct {
    Node* head[V];
} GraphList;

void initList(GraphList *g) {
    for(int i=0; i<V; i++) g->head[i] = NULL;
}

void addEdgeList(GraphList *g, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = g->head[src];
    g->head[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = src;
    newNode->next = g->head[dest];
    g->head[dest] = newNode;
}

int main() {
    // 1. Matrix Construction
    GraphMatrix gm;
    initMatrix(&gm);
    addEdgeMatrix(&gm, 0, 1);
    addEdgeMatrix(&gm, 0, 2);
    addEdgeMatrix(&gm, 1, 3);
    addEdgeMatrix(&gm, 3, 4);

    // 2. List Construction
    GraphList gl;
    initList(&gl);
    addEdgeList(&gl, 0, 1);
    addEdgeList(&gl, 0, 2);
    addEdgeList(&gl, 1, 3);
    addEdgeList(&gl, 3, 4);

    // 3. Comparison
    printf("\n--- Graph Representation Comparison (V=%d, E=4) ---\n", V);
    
    // Size Calculations
    long sizeMatrix = sizeof(gm);
    
    // Size of List = Array of pointers + (2 * E * size of Node)
    // 4 edges = 8 nodes (undirected)
    long sizeListHead = sizeof(gl); 
    long sizeNodes = 8 * sizeof(Node); 
    long totalSizeList = sizeListHead + sizeNodes;

    printf("1. Memory Usage:\n");
    printf("   Adjacency Matrix: %ld bytes (Fixed: V^2 * int)\n", sizeMatrix);
    printf("   Adjacency List:   %ld bytes (Dynamic: V*ptr + 2E*Node)\n", totalSizeList);
    
    printf("\n2. Analysis:\n");
    if (sizeMatrix > totalSizeList)
        printf("   -> Adjacency LIST is more memory efficient for this SPARSE graph.\n");
    else
        printf("   -> Adjacency MATRIX is more memory efficient.\n");

    printf("\n3. Conclusion:\n");
    printf("   - Use Matrix for DENSE graphs (E ~ V^2) or when O(1) edge check needed.\n");
    printf("   - Use List for SPARSE graphs (E << V^2) to save space.\n");

    return 0;
}
