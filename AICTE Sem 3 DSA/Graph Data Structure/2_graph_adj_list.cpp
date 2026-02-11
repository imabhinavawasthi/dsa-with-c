/*
 * File: 2_graph_adj_list.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Graph using Adjacency List in C++.
 * NO STL used. We implement a Linked List manually.
 *
 * Concepts:
 * - Dynamic memory allocation for nodes.
 * - Array of pointers to Linked Lists.
 * - Efficient for Sparse Graphs.
 */

#include <iostream>
using namespace std;

// Linked List Node
struct Node {
    int dest;
    Node* next;

    Node(int d) {
        dest = d;
        next = NULL;
    }
};

class GraphList {
private:
    int numVertices;
    Node** adjLists; // Pointer to array of pointers
    bool isDirected;

public:
    GraphList(int v, bool directed) {
        numVertices = v;
        isDirected = directed;
        
        adjLists = new Node*[v];
        for (int i = 0; i < v; i++)
            adjLists[i] = NULL;
    }

    void addEdge(int src, int dest) {
        // Add edge src -> dest
        Node* newNode = new Node(dest);
        newNode->next = adjLists[src];
        adjLists[src] = newNode;

        // If undirected, add dest -> src
        if (!isDirected) {
            Node* newNode2 = new Node(src);
            newNode2->next = adjLists[dest];
            adjLists[dest] = newNode2;
        }
        cout << "Edge added: " << src << " -> " << dest << endl;
    }

    void display() {
        cout << "\nAdjacency List:" << endl;
        for (int v = 0; v < numVertices; v++) {
            Node* temp = adjLists[v];
            cout << "Vertex " << v << ": ";
            while (temp) {
                cout << "-> " << temp->dest << " ";
                temp = temp->next;
            }
            cout << "-> NULL" << endl;
        }
    }

    // Print Out-Degree (or just Degree for Undirected)
    void printDegree(int v) {
        int count = 0;
        Node* temp = adjLists[v];
        while (temp) {
            count++;
            temp = temp->next;
        }
        if (isDirected)
            cout << "Out-Degree of Vertex " << v << ": " << count << endl;
        else
            cout << "Degree of Vertex " << v << ": " << count << endl;
    }

    ~GraphList() {
        for (int i = 0; i < numVertices; i++) {
            Node* temp = adjLists[i];
            while (temp) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adjLists;
    }
};

int main() {
    int v, type;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter Graph Type (0 for Undirected, 1 for Directed): ";
    cin >> type;

    GraphList g(v, (type == 1));

    // Example edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.display();

    cout << "\n--- Degree Info ---" << endl;
    g.printDegree(2);

    return 0;
}
