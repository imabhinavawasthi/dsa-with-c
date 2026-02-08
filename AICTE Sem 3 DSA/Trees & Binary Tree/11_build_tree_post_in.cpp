// File: 11_build_tree_post_in.cpp
// Purpose: Construct Binary Tree from In-order and Post-order Traversals
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

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive Build Function
// postIndex passed by Reference to maintain state
Node* buildTree(int in[], int post[], int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current root from end of postorder
    int val = post[postIndex--];
    Node* tNode = new Node(val);

    if (inStart == inEnd) return tNode;

    // Search in inorder
    int inIndex = search(in, inStart, inEnd, val);

    // IMPORTANT: Build RIGHT subtree first because we are traversing Postorder backwards
    // Postorder: Left -> Right -> Root. Backwards: Root -> Right -> Left.
    tNode->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    tNode->left = buildTree(in, post, inStart, inIndex - 1, postIndex);

    return tNode;
}

void printPreorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int len = sizeof(in) / sizeof(in[0]);
    int postIndex = len - 1;

    Node* root = buildTree(in, post, 0, len - 1, postIndex);

    cout << "Constructed Tree Pre-order Verification: ";
    printPreorder(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)
