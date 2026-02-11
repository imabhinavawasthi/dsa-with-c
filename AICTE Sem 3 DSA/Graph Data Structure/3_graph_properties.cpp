/*
 * File: 3_graph_properties.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program checks properties of a Graph:
 * 1. Connectivity
 * 2. Tree Status (Connected + Minimal Edges)
 * 3. Density
 *
 * Uses Adjacency List for representation.
 */

#include <iostream>
using namespace std;

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphProps {
    int V;
    Node** adj;

public:
    GraphProps(int v) {
        V = v;
        adj = new Node*[V];
        for(int i=0; i<V; i++) adj[i] = NULL;
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);
        newNode->next = adj[src];
        adj[src] = newNode;

        newNode = new Node(src);
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }

    int countEdges() {
        int count = 0;
        for(int i=0; i<V; i++) {
            Node* temp = adj[i];
            while(temp) {
                count++;
                temp = temp->next;
            }
        }
        return count / 2; // Undirected edges counted twice
    }

    void dfs(int v, bool visited[]) {
        visited[v] = true;
        Node* temp = adj[v];
        while(temp) {
            if(!visited[temp->dest])
                dfs(temp->dest, visited);
            temp = temp->next;
        }
    }

    bool isConnected() {
        bool* visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;

        dfs(0, visited);

        for(int i=0; i<V; i++) {
            if(!visited[i]) return false;
        }
        return true;
    }

    bool isTree() {
        return isConnected() && (countEdges() == V - 1);
    }
};

int main() {
    int V = 5;
    GraphProps g(V);

    // 0-1, 1-2, 2-3, 3-4 (Line Graph - Tree)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "\n--- Graph Properties (C++) ---\n";
    cout << "Vertices: " << V << endl;
    cout << "Edges: " << g.countEdges() << endl;

    if (g.isConnected())
        cout << "Connectivity: CONNECTED" << endl;
    else
        cout << "Connectivity: DISCONNECTED" << endl;

    if (g.isTree())
        cout << "Is Tree? YES" << endl;
    else
        cout << "Is Tree? NO" << endl;

    return 0;
}
