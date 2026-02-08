// File: 7_count_nodes.cpp
// Purpose: Count total number of nodes in a Binary Tree
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

int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    
    // Recursive Formula: 1 + Left + Right
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << "Total Nodes: " << countNodes(root) << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
