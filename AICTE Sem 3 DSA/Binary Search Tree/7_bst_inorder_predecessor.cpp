// File: 7_bst_inorder_predecessor.cpp
// Purpose: Find In-order Predecessor of a given node in BST
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

// Function to find In-order Predecessor
Node* getPredecessor(Node* root, Node* target) {
    // 1. If Left Child exists, finding right-most node in left subtree
    if (target->left != NULL) {
        Node* temp = target->left;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    // 2. Else, search from root
    Node* pred = NULL;
    Node* curr = root;
    while (curr != target) {
        if (target->data > curr->data) {
            pred = curr; // This node is smaller than target, so it is a candidate
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;
    /*
          20
         /  \
       10    30
    */
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);

    Node* target = search(root, 20);
    Node* pred = getPredecessor(root, target);

    if (pred) cout << "Predecessor of " << target->data << " is " << pred->data << endl;
    else cout << "No Predecessor logic for " << target->data << endl;

    return 0;
}

// Time Complexity: O(H)
// Space Complexity: O(1)
