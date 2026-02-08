// File: 2_binary_tree_linked.c
// Purpose: Implement binary tree using linked representation with a createNode function
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
// This function allocates memory, sets data, and initializes children to NULL
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Using Linked Representation to build the tree dynamicallly
    printf("Creating Binary Tree using Linked Representation:\n");

    // Level 0
    struct Node* root = createNode(1);
    
    // Level 1
    root->left = createNode(2);
    root->right = createNode(3);

    // Level 2
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /*
     * Tree Structure Constructed:
     *        1
     *      /   \
     *     2     3
     *    / \
     *   4   5
     */

    // Verification by printing connections
    printf("Root: %d\n", root->data);
    printf("Root->Left: %d\n", root->left->data);
    printf("Root->Right: %d\n", root->right->data);
    printf("Root->Left->Left: %d\n", root->left->left->data);
    printf("Root->Left->Right: %d\n", root->left->right->data);

    return 0;
}

// Time Complexity: O(1) per node creation
// Space Complexity: O(N) where N is number of nodes created
