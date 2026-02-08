// File: 1_bst_insert.c
// Purpose: Create a Binary Search Tree (BST) and insert nodes
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Binary Search Tree (BST) Property:
 * 1. The left subtree of a node contains only nodes with keys LESS than the node's key.
 * 2. The right subtree of a node contains only nodes with keys GREATER than the node's key.
 * 3. The left and right subtrees must also be binary search trees.
 * 
 * Insertion Logic (Recursive):
 * - If tree is empty, create root.
 * - If Key < Root -> Insert in Left Subtree.
 * - If Key > Root -> Insert in Right Subtree.
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

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    // 1. If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // 2. Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // 3. Return the (unchanged) node pointer
    return root;
}

// In-order traversal to verify BST property (Sorted Output)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Creating the BST
    // Insert: 50, 30, 20, 40, 70, 60, 80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Verification
    printf("BST Created. In-order Traversal (Should be sorted):\n");
    inorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: 
//   - Average: O(log N)
//   - Worst Case (Skewed): O(N)
// Space Complexity: O(N) (Recursion Stack)
