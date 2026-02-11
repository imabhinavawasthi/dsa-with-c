/*
 * File: 4_cycle_directed.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program detects cycles in a DIRECTED graph using DFS.
 * 
 * Concept:
 * We maintain a 'recursion stack' set. If we see a node that is already
 * in the current recursion stack, it means we have looped back to an ancestor.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphCycle {
    int V;
    Node* adj[MAX_V];
    bool visited[MAX_V];
    bool recStack[MAX_V];

public:
    GraphCycle(int v) {
        V = v;
        for(int i=0; i<V; i++) {
            adj[i] = NULL;
            visited[i] = false;
            recStack[i] = false;
        }
    }

    void addEdge(int s, int d) {
        Node* n = new Node(d);
        n->next = adj[s];
        adj[s] = n;
    }

    bool isCyclicUtil(int u) {
        visited[u] = true;
        recStack[u] = true;

        Node* temp = adj[u];
        while(temp) {
            int v = temp->dest;
            
            if(!visited[v]) {
                if(isCyclicUtil(v)) return true;
            }
            else if(recStack[v]) {
                return true; // Cycle found
            }
            temp = temp->next;
        }

        recStack[u] = false; // Remove from stack
        return false;
    }

    bool isCyclic() {
        for(int i=0; i<V; i++) {
            if(!visited[i])
                if(isCyclicUtil(i)) return true;
        }
        return false;
    }
};

int main() {
    int v = 4;
    GraphCycle g(v);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // Cycle: 3->1
    g.addEdge(3, 1);

    cout << "Checking for Cycle (Directed Graph)..." << endl;
    if(g.isCyclic())
        cout << "Result: Graph contains a CYCLE." << endl;
    else
        cout << "Result: Graph is ACYCLIC." << endl;

    return 0;
}
