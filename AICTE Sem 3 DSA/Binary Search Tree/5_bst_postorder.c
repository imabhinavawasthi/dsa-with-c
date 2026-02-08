// File: 5_bst_postorder.c
// Purpose: Post-order traversal of BST (Left -> Right -> Root)
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
 * Post-order Traversal (Left -> Right -> Root)
 * Useful for deleting the tree (visit children before parent).
 */
void postorder(struct Node* root) {
    if (root == NULL) return;

    // 1. Visit Left Subtree
    postorder(root->left);

    // 2. Visit Right Subtree
    postorder(root->right);

    // 3. Visit Root
    printf("%d ", root->data);
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

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H)
