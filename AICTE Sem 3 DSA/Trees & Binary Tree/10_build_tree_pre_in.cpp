// File: 10_build_tree_pre_in.cpp
// Purpose: Construct Binary Tree from In-order and Pre-order Traversals
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive Build Function
// preIndex is passed by Reference (&) to update globally
Node* buildTree(char in[], char pre[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) return NULL;

    // Select current node from Preorder
    char curr = pre[preIndex++];
    Node* tNode = new Node(curr);

    // If leaf node
    if (inStart == inEnd) return tNode;

    // Search index in Inorder
    int inIndex = search(in, inStart, inEnd, curr);

    // Build Left and Right subtrees
    tNode->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void printInorder(Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    
    // Starting index for preorder
    int preIndex = 0;

    Node* root = buildTree(in, pre, 0, len - 1, preIndex);

    cout << "Constructed Tree In-order Traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)
