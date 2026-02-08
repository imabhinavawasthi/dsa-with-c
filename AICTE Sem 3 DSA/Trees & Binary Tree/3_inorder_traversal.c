// File: 3_inorder_traversal.c
// Purpose: Implement and demonstrate In-order Traversal of a Binary Tree (Recursive)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * In-order Traversal Logic (Left -> Root -> Right):
 * 1. Recursively traverse the Left Subtree
 * 2. Visit (Print) the Root Node
 * 3. Recursively traverse the Right Subtree
 * 
 * It is called "In-order" because references to the root are visited "in between" children.
 */

// Node Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for In-order Traversal
void inorderTraversal(struct Node* root) {
    // Base Case: If the tree is empty (node is NULL), return
    if (root == NULL) {
        return;
    }

    // Recursive Step 1: Visit Left Subtree
    inorderTraversal(root->left);

    // Step 2: Visit Root Data
    printf("%d ", root->data);

    // Recursive Step 3: Visit Right Subtree
    inorderTraversal(root->right);
}

int main() {
    /*
     * Constructing the following tree:
     *        1
     *       / \
     *      2   3
     *     / \
     *    4   5
     */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order Traversal (Left -> Root -> Right): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N) - Every node is visited exactly once
// Space Complexity: O(N) - In worst case (skewed tree) stack depth is N. Average is O(log N).
