// File: 4_preorder_traversal.cpp
// Purpose: Implement Pre-order Traversal (Recursive)
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

// Pre-order: Root -> Left -> Right
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    // 1. Root
    cout << root->data << " ";

    // 2. Left
    preorderTraversal(root->left);

    // 3. Right
    preorderTraversal(root->right);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N) worst case (skewed tree)
