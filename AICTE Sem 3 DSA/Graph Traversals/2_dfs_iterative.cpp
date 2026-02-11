/*
 * File: 2_dfs_iterative.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Iterative DFS in C++.
 * NO STL used. We implement our own Stack class.
 * 
 * Key Concept:
 * Recursion uses internal stack. Iteration uses explicit stack.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

// Manual Stack Class
class Stack {
    int arr[MAX_V * 5];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(int x) { arr[++topIndex] = x; }
    int pop() { return arr[topIndex--]; }
    bool isEmpty() { return topIndex == -1; }
};

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphDFS {
    int V;
    Node* adj[MAX_V];
    bool visited[MAX_V];

public:
    GraphDFS(int v) {
        V = v;
        for(int i=0; i<V; i++) {
            adj[i] = NULL;
            visited[i] = false;
        }
    }

    void addEdge(int s, int d) {
        Node* n = new Node(d);
        n->next = adj[s];
        adj[s] = n;
    }

    void dfsIterative(int start) {
        Stack s;
        s.push(start);

        cout << "DFS Iterative from " << start << ": ";

        while(!s.isEmpty()) {
            int u = s.pop();

            if(!visited[u]) {
                visited[u] = true;
                cout << u << " ";
            }

            // Push neighbors
            // Note: Adjacency list is usually stored in reverse order of insertion.
            // Pushing neighbors as we traverse the list reverses them again on Stack.
            Node* temp = adj[u];
            while(temp) {
                if(!visited[temp->dest]) {
                    s.push(temp->dest);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {
    GraphDFS g(6);

    // 0 -> 1, 0 -> 2
    // 1 -> 3, 1 -> 4
    // 2 -> 5
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.dfsIterative(0);

    return 0;
}

// Time: O(V + E)
// Space: O(V)
