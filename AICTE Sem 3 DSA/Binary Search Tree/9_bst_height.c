// File: 9_bst_height.c
// Purpose: Find Height of BST and explain worst-case scenario
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Height Logic:
 * Height = 1 + Max(Height(Left), Height(Right))
 * 
 * WORST CASE BST (Skewed Tree):
 * If elements are inserted in sorted order (Ascending/Descending),
 * the BST becomes a chain (Linked List).
 * Height = N (Number of nodes).
 * Complexity of Search becomes O(N).
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

int findHeight(struct Node* root) {
    if (root == NULL) return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    struct Node* root = NULL;
    
    // Creating a Balanced Tree (Height ~ logN)
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);
    
    printf("Height of Balanced Tree (Nodes=7): %d\n", findHeight(root)); // Should be 3

    struct Node* skewedRoot = NULL;
    // Creating a Skewed Tree (Height = N)
    skewedRoot = insert(skewedRoot, 10);
    insert(skewedRoot, 20);
    insert(skewedRoot, 30);
    insert(skewedRoot, 40);

    printf("Height of Skewed Tree (Nodes=4): %d\n", findHeight(skewedRoot)); // Should be 4
    
    return 0;
}

// Time Complexity: O(N) (Must visit every node in worst case)
// Space Complexity: O(H) (Recursion Stack)
