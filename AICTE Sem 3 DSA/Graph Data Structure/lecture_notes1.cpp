// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int d) {
        val = d;
        next = NULL;
    }
};

void printLL(Node * head) {
    Node * curr = head;
    while(curr!=NULL) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
}

int main() {
    int V = 5;
    int E = 6;
    int edges[6][2] = {
        {1,2},
        {1,4},
        {0,4},
        {2,3},
        {1,3},
        {2,4}
    };
    
    Node** adjLists = new Node*[V];
    for (int i = 0; i < V; i++) {
        adjLists[i] = NULL;
    }
        
    for(int i = 0;i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // added v in u
        if(adjLists[u] == NULL) {
            adjLists[u] = new Node(v);
        }
        else {
            Node* newNode = new Node(v);
            newNode->next = adjLists[u];
            adjLists[u] = newNode;
        }
        // if undirected
        if(adjLists[v] == NULL) {
            adjLists[v] = new Node(u);
        }
        else {
            Node* newNode = new Node(u);
            newNode->next = adjLists[v];
            adjLists[v] = newNode;
        }
    }
    
    for(int i=0;i<V;i++) {
        cout<<i<<": ";
        printLL(adjLists[i]);
        cout<<"\n";
    }

    return 0;
}