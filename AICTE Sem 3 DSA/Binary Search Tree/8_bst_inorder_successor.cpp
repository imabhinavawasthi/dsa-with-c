// File: 8_bst_inorder_successor.cpp
// Purpose: Find In-order Successor of a given node in BST
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

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// Function to find In-order Successor
Node* getSuccessor(Node* root, Node* target) {
    // 1. If Right Child exists -> Go Right once, then all the way Left
    if (target->right != NULL) {
        Node* temp = target->right;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    // 2. If No Right Child -> Start from Root
    Node* succ = NULL;
    Node* curr = root;
    while (curr != target) {
        if (target->data < curr->data) {
            succ = curr; // Potential successor
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return succ;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20); insert(root, 10); insert(root, 30);
    
    // Find successor of 10 -> Should be 20 (Parent/Ancestor)
    Node* target = search(root, 10);
    Node* succ = getSuccessor(root, target);

    if (succ) cout << "Successor of " << target->data << " is " << succ->data << endl;
    else cout << "No Successor for " << target->data << endl;

    return 0;
}

// Time Complexity: O(H)
// Space Complexity: O(1)
