/*
 * File: 4_graph_comparison.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program allows comparing the two Graph representations.
 * 
 * Matrix: O(V^2) space. O(1) edge check.
 * List: O(V + E) space. O(degree) edge check.
 */

#include <iostream>
using namespace std;

#define V 100 // Let's use a larger V to emphasize difference

struct MatrixGraph {
    int mat[V][V];
};

struct ListNode {
    int dest;
    ListNode* next;
};

struct ListGraph {
    ListNode* head[V];
};

int main() {
    cout << "\n--- Graph Representation Comparison (V=" << V << ") ---" << endl;

    // 1. Matrix Size
    // Size = V * V * 4 bytes
    long matrixSize = sizeof(MatrixGraph);

    // 2. List Size (Assuming Sparse Graph with E = V, i.e., 100 edges)
    // Size = (V * 8 bytes (pointer)) + (2 * E * 16 bytes (node approx))
    // Note: Pointer size is 8 bytes on 64-bit systems.
    long listPointerArraySize = sizeof(ListGraph); 
    int estimatedEdges = V; 
    long listNodeSize = (2 * estimatedEdges) * sizeof(ListNode);
    long totalListSize = listPointerArraySize + listNodeSize;

    cout << "Scenario: Sparse Graph with " << V << " vertices and " << estimatedEdges << " edges." << endl;
    cout << "1. Adjacency Matrix Size: " << matrixSize << " bytes" << endl;
    cout << "2. Adjacency List Size:   " << totalListSize << " bytes" << endl;

    cout << "\nVerdict:" << endl;
    if (matrixSize > totalListSize) {
        cout << "   Adjacency List uses SIGNIFICANTLY less memory." << endl;
    } else {
        cout << "   Adjacency Matrix uses less memory." << endl;
    }

    cout << "\nTheoretical Comparison:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Feature          | Adjacency Matrix | Adjacency List |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Space            | O(V^2)           | O(V + E)       |" << endl;
    cout << "| Check Edge(u,v)  | O(1)             | O(Degree(u))   |" << endl;
    cout << "| Iterating Neighbors| O(V)           | O(Degree(u))   |" << endl;
    cout << "| Add Edge         | O(1)             | O(1)           |" << endl;
    cout << "| Remove Edge      | O(1)             | O(Degree(u))   |" << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}
