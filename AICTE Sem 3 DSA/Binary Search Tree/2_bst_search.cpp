// File: 2_bst_search.cpp
// Purpose: Search for an element in a Binary Search Tree
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

// Search Function
Node* search(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is smaller than root's key
    if (key < root->data)
        return search(root->left, key);
    
    // Key is greater than root's key
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);

    int key = 70;
    if (search(root, key))
        cout << "Element " << key << " Found." << endl;
    else
        cout << "Element " << key << " Not Found." << endl;

    return 0;
}

// Time Complexity: O(log N) Average
// Space Complexity: O(log N) Stack Space
