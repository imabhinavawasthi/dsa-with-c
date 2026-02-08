// File: 4_bst_preorder.c
// Purpose: Pre-order traversal of BST (Root -> Left -> Right)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

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

/*
 * Pre-order Traversal (Root -> Left -> Right)
 * Useful for copying the tree structure.
 */
void preorder(struct Node* root) {
    if (root == NULL) return;

    // 1. Visit Root
    printf("%d ", root->data);

    // 2. Visit Left Subtree
    preorder(root->left);

    // 3. Visit Right Subtree
    preorder(root->right);
}

int main() {
    struct Node* root = NULL;
    /*
        50
       /  \
     30    70
    */
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
