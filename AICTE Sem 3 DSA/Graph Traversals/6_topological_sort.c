/*
 * File: 6_topological_sort.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Topological Sort using DFS.
 * 
 * What is Topological Sort?
 * Linear ordering of vertices such that for every directed edge u -> v,
 * vertex u comes before v in the ordering.
 * 
 * Requirement:
 * Graph must be a DAG (Directed Acyclic Graph).
 * 
 * Logic:
 * 1. Visit a node.
 * 2. Recursively visit all its unvisited neighbors.
 * 3. AFTER visiting all neighbors, push the node to a Stack.
 * 4. Finally, pop everything from Stack to get Topological Order.
 * 
 * Why Stack?
 * The node that finishes last (has no dependencies or all dependencies met)
 * is pushed first. But we need it at the end. Stack reverses this order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Manual Stack
typedef struct Stack {
    int items[MAX_VERTICES];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX_VERTICES - 1)
        s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (s->top >= 0)
        return s->items[(s->top)--];
    return -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

// Graph Structure
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

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

void topoSortUtil(Graph* g, int v, Stack* s) {
    g->visited[v] = true;

    Node* temp = g->adjLists[v];
    while (temp) {
        if (!g->visited[temp->dest]) {
            topoSortUtil(g, temp->dest, s);
        }
        temp = temp->next;
    }

    // Push current vertex to stack which stores result
    push(s, v);
}

void topologicalSort(Graph* g) {
    Stack s;
    initStack(&s);

    // Call recursive helper function to check all vertices
    for (int i = 0; i < g->numVertices; i++) {
        if (!g->visited[i])
            topoSortUtil(g, i, &s);
    }

    printf("\nTopological Sort Order:\n");
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");
}

int main() {
    Graph g;
    int v = 6;
    initGraph(&g, v);

    // DAG Structure
    // 5 -> 2, 5 -> 0
    // 4 -> 0, 4 -> 1
    // 2 -> 3
    // 3 -> 1
    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);

    printf("Graph Created (DAG).\n");
    topologicalSort(&g);
    
    return 0;
}

// Time: O(V + E)
// Space: O(V)
