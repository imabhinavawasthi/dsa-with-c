// File: 1_avl_insertion.cpp
// Purpose: Implement AVL Tree Insertion with Rotations
// Author: Abhinav Awasthi

#include <iostream>
#include <algorithm> // for max
using namespace std;

// AVL Node Class
class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Helper to get height
int height(Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

// Get Balance Factor
int getBalance(Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

// Right Rotation
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Recursive Insert
Node* insert(Node* node, int key) {
    // 1. Normal BST Insert
    if (node == NULL) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // 2. Update Height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get Balance Factor
    int balance = getBalance(node);

    // 4. Rotations
    // Left Left
    if (balance > 1 && key < node->left->key) {
        cout << "Doing LL Rotation on " << node->key << endl;
        return rightRotate(node);
    }
    // Right Right
    if (balance < -1 && key > node->right->key) {
        cout << "Doing RR Rotation on " << node->key << endl;
        return leftRotate(node);
    }
    // Left Right
    if (balance > 1 && key > node->left->key) {
        cout << "Doing LR Rotation on " << node->key << endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left
    if (balance < -1 && key < node->right->key) {
        cout << "Doing RL Rotation on " << node->key << endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;

    cout << "Inserting 10, 20, 30..." << endl;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    cout << "Inserting 40, 50..." << endl;
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    cout << "Inserting 25..." << endl;
    root = insert(root, 25);

    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
