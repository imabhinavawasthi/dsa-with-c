// File: 8_count_leaf_nodes.c
// Purpose: Count number of leaf nodes in a Binary Tree
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Leaf Node: A node with no children (left = NULL and right = NULL)
 * Logic:
 * 1. If NULL, return 0.
 * 2. If Leaf, return 1.
 * 3. Else, return Leaves(Left) + Leaves(Right).
 */

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countLeafNodes(struct Node* root) {
    // Base Case
    if (root == NULL) {
        return 0;
    }

    // Check if it's a leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursive Step
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    /*
     * Tree:
     *      1
     *     / \
     *    2   3
     *   / \   \
     *  4   5   6
     * Leaves: 4, 5, 6 -> Total 3
     */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H) (Recursion Stack)
