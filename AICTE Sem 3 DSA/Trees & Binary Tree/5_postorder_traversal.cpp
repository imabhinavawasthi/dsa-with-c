// File: 5_postorder_traversal.cpp
// Purpose: Implement Post-order Traversal (Recursive)
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

// Post-order: Left -> Right -> Root
void postorderTraversal(Node* root) {
    if (root == NULL) return;

    // 1. Left
    postorderTraversal(root->left);

    // 2. Right
    postorderTraversal(root->right);

    // 3. Root
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
