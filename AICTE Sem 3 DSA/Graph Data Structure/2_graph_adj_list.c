/*
 * File: 2_graph_adj_list.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Graph using Adjacency List.
 * 
 * Adjacency List Representation:
 * An array of pointers 'adj[V]', where each 'adj[i]' points to a 
 * Linked List containing vertices connected to vertex 'i'.
 * 
 * Space Complexity: O(V + E)
 * - Best for Sparse Graphs (few edges).
 * - Saves memory compared to O(V^2) matrix.
 * 
 * Operations:
 * 1. Create Graph
 * 2. Add Edge (Directed / Undirected)
 * 3. Display Adjacency List
 * 4. Calculate Degree of a vertex
 */

#include <stdio.h>
#include <stdlib.h>

// Node for Adjacency List
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Graph Structure
typedef struct Graph {
    int numVertices;
    Node** adjLists; // Array of pointers to Node
    int isDirected;
} Graph;

// Create New Node
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Initialize Graph
Graph* createGraph(int vertices, int directed) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->isDirected = directed;

    // Create array of adjacency lists
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    // Initialize each list as empty
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add Edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // If undirected, add edge from dest to src
    if (!graph->isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
    printf("Edge added: %d -> %d\n", src, dest);
}

// Display Graph
void printGraph(Graph* graph) {
    printf("\nAdjacency List:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("-> NULL\n");
    }
}

// Calculate Degree of a Vertex
// For Undirected: Total edges connected.
// For Directed: Out-Degree (number of outgoing edges).
void printDegree(Graph* graph, int v) {
    int count = 0;
    Node* temp = graph->adjLists[v];
    while (temp) {
        count++;
        temp = temp->next;
    }
    
    if (graph->isDirected)
        printf("Out-Degree of Vertex %d is: %d\n", v, count);
    else
        printf("Degree of Vertex %d is: %d\n", v, count);
}

// For Directed Graph: Calculate In-Degree
// Requires traversing ALL lists. O(V + E).
void printInDegree(Graph* graph, int v) {
    if (!graph->isDirected) return; // Only for directed

    int count = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            if (temp->dest == v) {
                count++;
            }
            temp = temp->next;
        }
    }
    printf("In-Degree of Vertex %d is: %d\n", v, count);
}

int main() {
    int v = 5;
    int type;

    printf("Enter Graph Type (0 for Undirected, 1 for Directed): ");
    scanf("%d", &type);

    Graph* graph = createGraph(v, type);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("\n--- Vertex Degrees ---\n");
    printDegree(graph, 1); // Check degree of vertex 1
    
    if (type == 1) {
        printInDegree(graph, 1);
    }

    return 0;
}

// Time Complexity: 
// - Add Edge: O(1)
// - Display: O(V + E)
// - Degree (Out): O(Degree(V))
// - Degree (In): O(V + E) [Naive]
