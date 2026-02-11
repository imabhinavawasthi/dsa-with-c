/*
 * File: 9_bfs_shortest_path.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds Shortest Path in Unweighted Graph using BFS.
 */

#include <iostream>
using namespace std;

#define MAX_V 20

// Manual Queue
class Queue {
    int arr[MAX_V];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1; }
    void enqueue(int x) {
        if(front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        int item = arr[front];
        if(front >= rear) front = rear = -1;
        else front++;
        return item;
    }
};

struct Node {
    int dest;
    Node* next;
    Node(int d) { dest = d; next = NULL; }
};

class GraphSP {
    int V;
    Node* adj[MAX_V];
    int dist[MAX_V];

public:
    GraphSP(int v) {
        V = v;
        for(int i=0; i<V; i++) {
            adj[i] = NULL;
            dist[i] = -1; // -1 means unvisited/infinity
        }
    }

    void addEdge(int s, int d) {
        Node* n = new Node(d);
        n->next = adj[s];
        adj[s] = n;

        Node* n2 = new Node(s);
        n2->next = adj[d];
        adj[d] = n2;
    }

    void bfsDist(int start) {
        Queue q;
        dist[start] = 0;
        q.enqueue(start);

        while(!q.isEmpty()) {
            int u = q.dequeue();
            
            Node* temp = adj[u];
            while(temp) {
                int v = temp->dest;
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.enqueue(v);
                }
                temp = temp->next;
            }
        }

        cout << "\nShortest Path Distances from " << start << ":" << endl;
        for(int i=0; i<V; i++) {
            cout << "To Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int v = 6;
    GraphSP g(v);

    // 0-1, 0-2
    // 1-3
    // 2-3
    // 3-4, 4-5
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfsDist(0);

    return 0;
}
