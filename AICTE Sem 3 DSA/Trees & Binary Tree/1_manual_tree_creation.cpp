// File: 1_manual_tree_creation.cpp
// Purpose: Create a binary tree manually and display it
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

/*
 * Tree ADT (Abstract Data Type) Concept:
 * A Binary Tree is a hierarchical structure where each node has:
 * 1. Data
 * 2. Pointer to left child
 * 3. Pointer to right child
 */

// Define the Class / Struct for a tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main() {
    // 1. Manually create nodes using 'new'
    // Tree Structure:
    //      10
    //     /  \
    //   20    30

    Node* root = new Node(10);        // Create root
    Node* leftChild = new Node(20);   // Create left child
    Node* rightChild = new Node(30);  // Create right child

    // 2. Link the nodes
    root->left = leftChild;
    root->right = rightChild;

    // 3. Display manually
    cout << "Binary Tree Manually Created:" << endl;
    cout << "Root Node: " << root->data << endl;
    cout << "Root->Left: " << root->left->data << endl;
    cout << "Root->Right: " << root->right->data << endl;

    // 4. Free memory manually using 'delete'
    delete leftChild;
    delete rightChild;
    delete root;
    
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
