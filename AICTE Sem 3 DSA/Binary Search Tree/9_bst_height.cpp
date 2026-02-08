// File: 9_bst_height.cpp
// Purpose: Find Height of BST
// Author: Abhinav Awasthi

#include <iostream>
#include <algorithm> // for max
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

Node* insert(Node* root, int data) {
    if (root == NULL) return new Node(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int findHeight(Node* root) {
    if (root == NULL) return 0;
    
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20); // Left Left
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80); // Right Right

    cout << "Height of BST: " << findHeight(root) << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
