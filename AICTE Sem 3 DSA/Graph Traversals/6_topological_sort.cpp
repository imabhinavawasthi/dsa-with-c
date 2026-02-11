/*
 * File: 6_topological_sort.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Topological Sort in C++ for Directed Acyclic Graphs (DAG).
 * 
 * Uses DFS + Stack technique.
 * Logic: A vertex is pushed to stack only when all its adjacent vertices 
 * (and their subtrees) are visited.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

// Manual Stack
class Stack {
    int arr[MAX_V];
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

class GraphTopo {
    int V;
    Node* adj[MAX_V];
    bool visited[MAX_V];

public:
    GraphTopo(int v) {
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

    void topoSortUtil(int v, Stack& s) {
        visited[v] = true;

        Node* temp = adj[v];
        while(temp) {
            if(!visited[temp->dest])
                topoSortUtil(temp->dest, s);
            temp = temp->next;
        }

        s.push(v);
    }

    void topologicalSort() {
        Stack s;

        for(int i=0; i<V; i++) {
            if(!visited[i])
                topoSortUtil(i, s);
        }

        cout << "Topological Sort Order: ";
        while(!s.isEmpty()) {
            cout << s.pop() << " ";
        }
        cout << endl;
    }
};

int main() {
    GraphTopo g(6);

    // 5 -> 2, 5 -> 0
    // 4 -> 0, 4 -> 1
    // 2 -> 3
    // 3 -> 1
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort (DAG):" << endl;
    g.topologicalSort();

    return 0;
}
