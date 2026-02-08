// File: 6_bst_skewed_creation.cpp
// Purpose: Demonstrate Skewed BST (Worst Case) creation
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

Node* insert(Node* root, int data) {
    if (root == NULL) return new Node(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    
    // Inserting Sorted Data
    cout << "Inserting: 1, 2, 3, 4, 5" << endl;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    /*
     * Structure:
     * 1
     *  \
     *   2
     *    \
     *     3...
     */

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Verification of Skewness:" << endl;
    if (root->right != NULL) cout << "Root->Right is " << root->right->data << endl;
    if (root->left == NULL) cout << "Root->Left is NULL (Correct)" << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
