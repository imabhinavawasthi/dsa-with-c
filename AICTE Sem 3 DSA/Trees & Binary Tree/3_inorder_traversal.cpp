// File: 3_inorder_traversal.cpp
// Purpose: Implement and demonstrate In-order Traversal of a Binary Tree (Recursive)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

// Node Class
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

/*
 * In-order Traversal (L -> Root -> R)
 * Uses recursion stack implicitly.
 */
void inorderTraversal(Node* root) {
    // Base Case
    if (root == NULL)
        return;

    // 1. Go Left
    inorderTraversal(root->left);

    // 2. Process Dat
    cout << root->data << " ";

    // 3. Go Right
    inorderTraversal(root->right);
}

int main() {
    /*
     * Tree:
     *      A(10)
     *     /     \
     *   B(20)  C(30)
     */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H) where H is height of tree (Stack space)
