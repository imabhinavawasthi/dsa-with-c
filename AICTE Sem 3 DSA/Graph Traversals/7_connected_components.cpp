/*
 * File: 7_connected_components.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds Connected Components in C++.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphCC {
    int V;
    Node* adj[MAX_V];
    bool visited[MAX_V];

public:
    GraphCC(int v) {
        V = v;
        for(int i=0; i<V; i++) {
            adj[i] = NULL;
            visited[i] = false;
        }
    }

    void addEdge(int s, int d) {
        // Undirected
        Node* n = new Node(d);
        n->next = adj[s];
        adj[s] = n;

        Node* n2 = new Node(s);
        n2->next = adj[d];
        adj[d] = n2;
    }

    void dfs(int v) {
        visited[v] = true;
        cout << v << " ";

        Node* temp = adj[v];
        while(temp) {
            if(!visited[temp->dest])
                dfs(temp->dest);
            temp = temp->next;
        }
    }

    void findComponents() {
        int count = 0;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                cout << "Component " << ++count << ": ";
                dfs(i);
                cout << endl;
            }
        }
        cout << "\nTotal Components: " << count << endl;
    }
};

int main() {
    GraphCC g(7);
    
    // Component 1: 0-1-2
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // Component 2: 3-4
    g.addEdge(3, 4);

    // Component 3: 5-6 (Isolated pair)
    g.addEdge(5, 6);

    cout << "--- Connected Components ---" << endl;
    g.findComponents();

    return 0;
}
