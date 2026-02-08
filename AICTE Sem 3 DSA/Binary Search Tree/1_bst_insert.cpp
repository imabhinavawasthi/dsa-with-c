// File: 1_bst_insert.cpp
// Purpose: Create a Binary Search Tree (BST) and insert nodes
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

// BST Node Class
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

// Function to insert a node
Node* insert(Node* root, int data) {
    // Base Case: If tree is empty
    if (root == NULL) {
        return new Node(data);
    }

    // Recursive Logic
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order Traversal to Print
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert Nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "BST Created. In-order Traversal:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}

// Time Complexity: Average O(log N), Worst O(N)
// Space Complexity: O(N)
