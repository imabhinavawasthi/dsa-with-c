// File: 8_pq_avl.cpp
// Purpose: Implement Priority Queue using AVL Tree
// Author: Abhinav Awasthi

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    int height;
    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

// ... Standard AVL Helper Functions ...
int height(Node *N) { return (N == NULL) ? 0 : N->height; }
int getBalance(Node *N) { return (N == NULL) ? 0 : height(N->left) - height(N->right); }

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left); return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right); return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

int main() {
    Node *pq = NULL;
    pq = insert(pq, 50);
    pq = insert(pq, 20);
    pq = insert(pq, 30); // Becomes Balanced
    
    Node* min = minValueNode(pq);
    cout << "Min Priority (Head of Queue): " << min->key << endl;

    cout << "Compared to Binary Heap PQ:" << endl;
    cout << "- AVL Find Min: O(log N) (Heap is O(1))" << endl;
    cout << "- AVL Insert/Delete: O(log N) (Same as Heap)" << endl;
    
    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
