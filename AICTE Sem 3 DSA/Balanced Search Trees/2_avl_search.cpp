// File: 2_avl_search.cpp
// Purpose: Search for an element in an AVL Tree
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

int main() {
    Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);

    int key = 40;
    if (search(root, key))
        cout << "Element " << key << " found." << endl;
    else
        cout << "Element " << key << " Not Found." << endl;

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(log N)
