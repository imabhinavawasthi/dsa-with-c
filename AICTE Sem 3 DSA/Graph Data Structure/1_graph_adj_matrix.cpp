/*
 * File: 1_graph_adj_matrix.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Graph using Adjacency Matrix in C++.
 * NO STL used.
 *
 * Concepts:
 * - Adjacency Matrix is a 2D array representation.
 * - Ideally suited for Dense Graphs where E is close to V^2.
 * - Constant time O(1) to check if an edge exists.
 */

#include <iostream>
using namespace std;

#define MAX_VERTICES 20

class GraphMatrix {
private:
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    bool isDirected;

public:
    GraphMatrix(int v, bool directed) {
        numVertices = v;
        isDirected = directed;

        // Initialize matrix with 0
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid Vertex!" << endl;
            return;
        }

        adjMatrix[src][dest] = 1;

        if (!isDirected) {
            adjMatrix[dest][src] = 1;
        }
        cout << "Edge added: " << src << " -> " << dest << endl;
    }

    void removeEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid Vertex!" << endl;
            return;
        }

        adjMatrix[src][dest] = 0;

        if (!isDirected) {
            adjMatrix[dest][src] = 0;
        }
        cout << "Edge removed: " << src << " -> " << dest << endl;
    }

    bool hasEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices) return false;
        return (adjMatrix[src][dest] == 1);
    }

    void display() {
        cout << "\nAdjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < numVertices; i++) cout << i << " ";
        cout << endl;

        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int v, choice, type, src, dest;

    cout << "Enter number of vertices (max " << MAX_VERTICES << "): ";
    cin >> v;

    cout << "Enter Graph Type (0 for Undirected, 1 for Directed): ";
    cin >> type;

    GraphMatrix g(v, (type == 1));

    while (true) {
        cout << "\n--- Graph Operations (C++) ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Check Edge\n";
        cout << "4. Display Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Source and Destination: ";
                cin >> src >> dest;
                g.addEdge(src, dest);
                break;
            case 2:
                cout << "Enter Source and Destination: ";
                cin >> src >> dest;
                g.removeEdge(src, dest);
                break;
            case 3:
                cout << "Enter Source and Destination: ";
                cin >> src >> dest;
                if (g.hasEdge(src, dest))
                    cout << "Edge Exists." << endl;
                else
                    cout << "Edge DOES NOT Exist." << endl;
                break;
            case 4:
                g.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}

// Time Complexity: O(1) for adding/removing/checking edges.
// Space Complexity: O(V^2) - Fixed size matrix.
