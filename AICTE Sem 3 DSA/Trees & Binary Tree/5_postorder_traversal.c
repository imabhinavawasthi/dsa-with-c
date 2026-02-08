// File: 5_postorder_traversal.c
// Purpose: Implement Post-order Traversal (Recursive)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Post-order Traversal Logic (Left -> Right -> Root):
 * 1. Recursively traverse the Left Subtree
 * 2. Recursively traverse the Right Subtree
 * 3. Visit (Print) the Root Node
 * 
 * "Post" means root is visited AFTER children.
 * Used for deleting trees (delete children before parent).
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

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;

    // 1. Visit Left
    postorderTraversal(root->left);

    // 2. Visit Right
    postorderTraversal(root->right);

    // 3. Visit Root
    printf("%d ", root->data);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Post-order Traversal (Left -> Right -> Root): ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
