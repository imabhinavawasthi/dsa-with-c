// File: 1_manual_tree_creation.c
// Purpose: Create a binary tree manually and display it
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Tree ADT (Abstract Data Type) Concept:
 * A Tree is a non-linear data structure.
 * A Binary Tree is a tree where every node has at most 2 children (Left and Right).
 * 
 * Node Structure in Linked Representation:
 * [ Left Pointer | Data | Right Pointer ]
 */

// Define the structure for a tree node
struct Node {
    int data;               // Data part
    struct Node* left;      // Pointer to left child
    struct Node* right;     // Pointer to right child
};

int main() {
    // 1. Manually allocate memory for nodes using malloc
    // We are creating a simple tree:
    //      10
    //     /  \
    //   20    30
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    struct Node* leftChild = (struct Node*)malloc(sizeof(struct Node));
    struct Node* rightChild = (struct Node*)malloc(sizeof(struct Node));

    // 2. Assign data to nodes
    root->data = 10;
    leftChild->data = 20;
    rightChild->data = 30;

    // 3. Link the nodes manually
    root->left = leftChild;     // 10 -> left is 20
    root->right = rightChild;   // 10 -> right is 30
    
    // 4. Important: Initialize children of leaf nodes to NULL
    leftChild->left = NULL;
    leftChild->right = NULL;
    rightChild->left = NULL;
    rightChild->right = NULL;

    // 5. Display the tree contents manually to verify
    printf("Binary Tree Manually Created:\n");
    printf("Root Node: %d\n", root->data);
    printf("Root->Left: %d\n", root->left->data);
    printf("Root->Right: %d\n", root->right->data);

    // Free allocated memory (Good practice, though OS handles it on exit)
    free(leftChild);
    free(rightChild);
    free(root);

    return 0;
}

// Time Complexity: O(1) - Just creating 3 nodes
// Space Complexity: O(1) - Constant space for 3 nodes
