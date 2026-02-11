/*
 * File: 2_dfs_iterative.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Depth First Search (DFS) ITERATIVELY.
 * 
 * Why Iterative?
 * - Avoids recursion depth limit (Stack Overflow).
 * - Explicit control over the traversal process.
 * 
 * Stack Implementation:
 * Since we cannot use STL, we implement a simple array-based Stack.
 * 
 * Logic:
 * 1. Push start vertex to Stack.
 * 2. While Stack is not empty:
 *      a. Pop vertex V.
 *      b. If V is not visited:
 *          i. Mark V as visited.
 *          ii. Push all unvisited neighbors of V to Stack.
 * 
 * Note: Neighbors are pushed in reverse order to simulate recursion order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// --- Stack Implementation ---
typedef struct Stack {
    int items[MAX_VERTICES * 2]; // *2 to be safe
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top >= MAX_VERTICES * 2 - 1) return;
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[(s->top)--];
}

// --- Adjacency List ---
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

// --- DFS Iterative Logic ---
void DFS_Iterative(Graph* g, int startVertex) {
    Stack s;
    initStack(&s);

    // 1. Push start vertex
    push(&s, startVertex);

    printf("\nDFS Iterative Traversal starting from %d: ", startVertex);

    while (!isEmpty(&s)) {
        // 2. Pop
        int currentVertex = pop(&s);

        // 3. Process if not visited yet
        // Note: Vertices might be pushed multiple times, so check visited after popping
        if (!g->visited[currentVertex]) {
            g->visited[currentVertex] = true;
            printf("%d ", currentVertex);
        }

        // 4. Push all unvisited neighbors
        Node* temp = g->adjLists[currentVertex];
        while (temp) {
            if (!g->visited[temp->dest]) {
                push(&s, temp->dest);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int v = 5;
    initGraph(&g, v);

    // 0 -> 1, 0 -> 2
    // 1 -> 3
    // 2 -> 4
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);

    DFS_Iterative(&g, 0);

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V) (Stack space)
