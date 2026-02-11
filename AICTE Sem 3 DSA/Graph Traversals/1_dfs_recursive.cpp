/*
 * File: 1_dfs_recursive.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Recursive DFS in C++.
 * NO STL used.
 * 
 * We adhere to the system stack approach for recursion.
 */

#include <iostream>
using namespace std;

// Maximum Vertices
#define MAX_V 20

// Adjacency List Node
struct Node {
    int dest;
    Node* next;
    
    Node(int d) {
        dest = d;
        next = NULL;
    }
};

class GraphDFS {
    int numVertices;
    Node* adjLists[MAX_V];
    bool visited[MAX_V];

public:
    GraphDFS(int v) {
        numVertices = v;
        for (int i = 0; i < v; i++) {
            adjLists[i] = NULL;
            visited[i] = false;
        }
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);
        newNode->next = adjLists[src];
        adjLists[src] = newNode;
        
        // Uncomment for undirected
        // Node* newNode2 = new Node(src);
        // newNode2->next = adjLists[dest];
        // adjLists[dest] = newNode2;
    }

    // Core Recursive Function
    void dfsUtil(int v) {
        // Mark and Print
        visited[v] = true;
        cout << v << " ";

        // Recurse for all neighbors
        Node* temp = adjLists[v];
        while (temp) {
            if (!visited[temp->dest]) {
                dfsUtil(temp->dest);
            }
            temp = temp->next;
        }
    }

    void performDFS(int startVertex) {
        // Build fresh visited array for each run (resetting in constructor only works once)
        for(int i=0; i<numVertices; i++) visited[i] = false;

        cout << "\nStarting DFS from " << startVertex << ": ";
        dfsUtil(startVertex);
        cout << endl;
    }
};

int main() {
    GraphDFS g(5);

    // 0 -> 1, 0 -> 2
    // 1 -> 3
    // 2 -> 4
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Graph Edges (0->1, 0->2, 1->3, 2->4)" << endl;
    
    g.performDFS(0);

    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V) (System Stack)
