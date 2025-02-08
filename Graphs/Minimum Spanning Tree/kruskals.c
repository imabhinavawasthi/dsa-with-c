#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices
#define INF 99999 // A large value representing infinity

// Structure for an edge
typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX]; // List of edges
int n, e; // Number of vertices and edges

// Compare function for sorting edges based on weight
int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// DFS function to check if two nodes are in the same component
void dfs(int graph[MAX][MAX], int visited[MAX], int node) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

// Function to check if adding an edge forms a cycle
int isSameComponent(int u, int v, int graph[MAX][MAX]) {
    int visited[MAX] = {0};
    
    // Run DFS from u
    dfs(graph, visited, u);

    // If v is visited, then u and v are in the same component
    return visited[v];
}

// Kruskal's Algorithm for MST
void kruskal() {
    int mst[MAX][MAX] = {0};
    int totalWeight = 0, edgesUsed = 0;

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), compare);

    // Iterate through sorted edges
    for (int i = 0; i < e; i++) {
        int u = edges[i].u, v = edges[i].v, weight = edges[i].weight;

        // If u and v are not in the same component, add the edge to MST
        if (!isSameComponent(u, v, mst)) {
            mst[u][v] = mst[v][u] = weight; // Add to MST
            totalWeight += weight;
            edgesUsed++;
            printf("Edge (%d - %d) - %d\n", u, v, weight);
        }

        if(edgesUsed == n-1) {
            break;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    n = 6;
    e = 8;
    
    int mat[8][3] = {
        {0,2,4},
        {0,1,4},
        {1,2,2},
        {2,3,3},
        {2,4,2},
        {2,5,4},
        {3,5,3},
        {4,5,3}
    };

    for (int i = 0; i < e; i++) {
        edges[i].u = mat[i][0];
        edges[i].v = mat[i][1];
        edges[i].weight = mat[i][2];
    }

    kruskal();

    return 0;
}
