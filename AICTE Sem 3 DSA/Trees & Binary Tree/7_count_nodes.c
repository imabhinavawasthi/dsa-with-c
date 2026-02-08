// File: 7_count_nodes.c
// Purpose: Count total number of nodes in a Binary Tree
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Logic:
 * Total Nodes = 1 (Root) + Nodes in Left Subtree + Nodes in Right Subtree
 * Base Case: If root is NULL, count is 0.
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

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    /*
     * Tree:
     *      1
     *     / \
     *    2   3
     *       / \
     *      4   5
     * Total nodes: 5
     */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printf("Total number of nodes: %d\n", countNodes(root));

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
