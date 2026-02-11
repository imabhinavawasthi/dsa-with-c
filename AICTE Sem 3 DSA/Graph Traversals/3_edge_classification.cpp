/*
 * File: 3_edge_classification.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program classifies edges (Tree, Back, Forward, Cross) in C++.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class EdgeClassifier {
    int V;
    Node* adj[MAX_V];
    int startTime[MAX_V];
    int endTime[MAX_V];
    bool visited[MAX_V];
    int time;

public:
    EdgeClassifier(int v) {
        V = v;
        time = 0;
        for(int i=0; i<V; i++) {
            adj[i] = NULL;
            startTime[i] = 0;
            endTime[i] = 0;
            visited[i] = false;
        }
    }

    void addEdge(int s, int d) {
        Node* n = new Node(d);
        n->next = adj[s];
        adj[s] = n;
    }

    void dfs(int u) {
        visited[u] = true;
        startTime[u] = ++time;

        Node* temp = adj[u];
        while(temp) {
            int v = temp->dest;

            if(!visited[v]) {
                cout << "(" << u << " -> " << v << "): TREE EDGE" << endl;
                dfs(v);
            }
            else {
                if(endTime[v] == 0) {
                    cout << "(" << u << " -> " << v << "): BACK EDGE (Cycle)" << endl;
                }
                else if(startTime[u] < startTime[v]) {
                    cout << "(" << u << " -> " << v << "): FORWARD EDGE" << endl;
                }
                else {
                    cout << "(" << u << " -> " << v << "): CROSS EDGE" << endl;
                }
            }
            temp = temp->next;
        }
        endTime[u] = ++time;
    }

    void classify() {
        cout << "\nEdge Types (Directed Graph):" << endl;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
    }
};

int main() {
    EdgeClassifier g(5);

    // 0->1, 1->2, 2->0 (Back), 1->3 (Tree), 3->1 (Back)
    // 0->3 (Forward - if 3 visited via 1 first)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(0, 3);

    g.classify();

    return 0;
}

// Time: O(V + E)
// Space: O(V)
