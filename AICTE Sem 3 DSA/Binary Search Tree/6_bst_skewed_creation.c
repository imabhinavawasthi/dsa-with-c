// File: 6_bst_skewed_creation.c
// Purpose: Demonstrate Skewed BST (Worst Case) by inserting sorted data
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Skewed Binary Search Tree:
 * A BST where every node has only one child (either left or right).
 * 
 * Cause:
 * Inserting elements in sorted order (Ascending or Descending).
 * 
 * Consequence:
 * Height becomes O(N) instead of O(log N).
 * Search/Insert/Delete operations degrade to O(N).
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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    printf("Inserting Sorted Data: 10, 20, 30, 40, 50\n");
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    /*
     * Resulting Tree Structure (Right Skewed):
     * 10
     *   \
     *    20
     *      \
     *       30
     *         \
     *          40
     *            \
     *             50
     */

    printf("In-order Traversal (Verified): ");
    inorder(root); // Should print 10 20 30 40 50
    printf("\n");
    
    printf("Verify Skewed Nature manually:\n");
    printf("Root: %d\n", root->data);
    printf("Root->Right: %d\n", root->right->data);
    printf("Root->Right->Right: %d\n", root->right->right->data);

    return 0;
}

// Time Complexity: O(N) for insertion in skewed tree
// Space Complexity: O(N) Recursion Stack
