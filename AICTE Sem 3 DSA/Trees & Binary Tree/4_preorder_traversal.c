// File: 4_preorder_traversal.c
// Purpose: Implement Pre-order Traversal (Recursive)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Pre-order Traversal Logic (Root -> Left -> Right):
 * 1. Visit (Print) the Root Node
 * 2. Recursively traverse the Left Subtree
 * 3. Recursively traverse the Right Subtree
 * 
 * "Pre" means root is visited BEFORE children.
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

void preorderTraversal(struct Node* root) {
    // Base Case
    if (root == NULL) return;

    // 1. Visit Root
    printf("%d ", root->data);

    // 2. Visit Left
    preorderTraversal(root->left);

    // 3. Visit Right
    preorderTraversal(root->right);
}

int main() {
    /*
     * Tree:
     *       1
     *      / \
     *     2   3
     */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Pre-order Traversal (Root -> Left -> Right): ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H) (Recursion Stack)
