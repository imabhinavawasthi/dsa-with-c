// File: 3_bst_inorder.c
// Purpose: In-order traversal of BST (Produces Sorted Output)
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
 * In-order Traversal (Left -> Root -> Right)
 * Key Property in BST: This always visits nodes in ASCENDING (SORTED) order.
 */
void inorder(struct Node* root) {
    if (root == NULL) return;

    // 1. Visit Left Subtree
    inorder(root->left);

    // 2. Visit Root
    printf("%d ", root->data);

    // 3. Visit Right Subtree
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    // Insert: 50, 30, 70, 20, 40, 60, 80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-order Traversal (Sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H) (Log N to N)
