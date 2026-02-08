// File: 10_bst_balance_factor.cpp
// Purpose: Compute Balance Factor to understand Tree Balancing
// Author: Abhinav Awasthi

#include <iostream>
#include <algorithm>
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

int getHeight(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getBalanceFactor(Node* root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void showBalanceFactors(Node* root) {
    if (root == NULL) return;
    showBalanceFactors(root->left);
    cout << "Node: " << root->data << " | Balance Factor: " << getBalanceFactor(root) << endl;
    showBalanceFactors(root->right);
}

int main() {
    Node* root = NULL;
    // Unbalanced Tree
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);

    cout << "Calculating Balance Factors:" << endl;
    showBalanceFactors(root);

    return 0;
}

// Time Complexity: O(N^2) as getHeight is called for every node
// Space Complexity: O(N)
