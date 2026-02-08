// File: 8_count_leaf_nodes.cpp
// Purpose: Count number of leaf nodes in a Binary Tree
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    // Condition for Leaf Node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count leaves in subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    // Only root->left and root->right are leaves here
    cout << "Number of Leaf Nodes: " << countLeafNodes(root) << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
