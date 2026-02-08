// File: 9_search_binary_tree.cpp
// Purpose: Search for an element in a binary tree (Ordinary Binary Tree)
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

bool search(Node* root, int key) {
    // Base Case
    if (root == NULL) return false;

    // Check current node
    if (root->data == key) return true;

    // Search Left, then Right using OR operator
    // Short-circuiting: if search(left) is true, search(right) won't execute
    return search(root->left, key) || search(root->right, key);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);

    int key = 8;
    if (search(root, key))
        cout << "Element " << key << " found." << endl;
    else
        cout << "Element " << key << " not found." << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
