// File: 2_binary_tree_linked.cpp
// Purpose: Implement binary tree using linked representation with a helper function
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

// Class for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Helper function to connect two nodes (Optional, but shows flexibility)
// parent: pointer to parent node
// child: pointer to child node
// isLeft: true if connecting to left, false for right
void connect(Node* parent, Node* child, bool isLeft) {
    if (isLeft) {
        parent->left = child;
    } else {
        parent->right = child;
    }
}

int main() {
    cout << "Creating Binary Tree using Linked Representation (Nodes & Pointers)" << endl;

    // Creating nodes using 'new'
    Node* root = new Node(100);
    Node* n1 = new Node(200);
    Node* n2 = new Node(300);
    Node* n3 = new Node(400);

    // Linking them to form a structure
    //      100
    //     /   \
    //   200   300
    //   /
    // 400

    root->left = n1;
    root->right = n2;
    n1->left = n3;

    // Display to verify
    cout << "Root: " << root->data << endl;
    cout << "Left Child (200): " << root->left->data << endl;
    cout << "Right Child (300): " << root->right->data << endl;
    cout << "Left->Left Child (400): " << root->left->left->data << endl;

    return 0;
}

// Time Complexity: O(1) per node
// Space Complexity: O(N) for N nodes
