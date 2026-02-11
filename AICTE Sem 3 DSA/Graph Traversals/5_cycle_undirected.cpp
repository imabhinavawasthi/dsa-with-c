/*
 * File: 5_cycle_undirected.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program detects cycles in an UNDIRECTED graph using DFS.
 * 
 * Strategy:
 * When visiting neighbors, if we encounter an already visited node
 * that is NOT the parent of the current node, then a cycle exists.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphCycleUndirected {
    int V;
    Node* adj[MAX_V];
    bool visited[MAX_V];

public:
    GraphCycleUndirected(int v) {
        V = v;
        for(int i=0; i<V; i++) {
            adj[i] = NULL;
            visited[i] = false;
        }
    }

    void addEdge(int s, int d) {
        // Undirected: Add both ways
        Node* n = new Node(d);
        n->next = adj[s];
        adj[s] = n;

        Node* n2 = new Node(s);
        n2->next = adj[d];
        adj[d] = n2;
    }

    bool isCyclicUtil(int u, int parent) {
        visited[u] = true;

        Node* temp = adj[u];
        while(temp) {
            int v = temp->dest;
            
            if(!visited[v]) {
                if(isCyclicUtil(v, u)) return true;
            }
            // If visited and not parent -> Cycle
            else if(v != parent) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isCyclic() {
        for(int i=0; i<V; i++) {
            if(!visited[i])
                if(isCyclicUtil(i, -1)) return true;
        }
        return false;
    }
};

int main() {
    int v = 4;
    GraphCycleUndirected g(v);

    // 0-1, 1-2, 2-3 (No cycle)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Checking for Cycle (Undirected)..." << endl;
    if(g.isCyclic())
        cout << "Result: Graph contains a CYCLE." << endl;
    else
        cout << "Result: Graph is ACYCLIC." << endl;

    return 0;
}
