/*
 * File: 8_bfs.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Breadth First Search (BFS) in C++.
 * NO STL used. We implement a custom Queue class.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

// Manual Queue Class
class Queue {
    int arr[MAX_V];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    
    bool isEmpty() { return front == -1; }

    void enqueue(int x) {
        if(rear == MAX_V - 1) return;
        if(front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if(isEmpty()) return -1;
        int item = arr[front];
        if(front >= rear)
            front = rear = -1;
        else
            front++;
        return item;
    }
};

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphBFS {
    int V;
    Node* adj[MAX_V];
    bool visited[MAX_V];

public:
    GraphBFS(int v) {
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

    void bfs(int startVertex) {
        Queue q;
        
        visited[startVertex] = true;
        q.enqueue(startVertex);

        cout << "BFS Traversal: ";

        while(!q.isEmpty()) {
            int u = q.dequeue();
            cout << u << " ";

            Node* temp = adj[u];
            while(temp) {
                if(!visited[temp->dest]) {
                    visited[temp->dest] = true;
                    q.enqueue(temp->dest);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {
    GraphBFS g(4);

    // 0->1, 0->2
    // 1->2
    // 2->0 
    // 2->3
    // 3->3
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(2);

    return 0;
}
