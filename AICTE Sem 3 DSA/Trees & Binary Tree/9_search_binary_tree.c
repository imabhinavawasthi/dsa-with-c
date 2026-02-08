// File: 9_search_binary_tree.c
// Purpose: Search for an element in a binary tree (Ordinary Binary Tree, NOT BST)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Search Logic (Pre-order approach):
 * 1. If Root is NULL, return 0 (Not Found).
 * 2. If Root->Data == Key, return 1 (Found).
 * 3. Search in Left Subtree. If found, return 1.
 * 4. Search in Right Subtree. If found, return 1.
 * 5. Return 0.
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

int search(struct Node* root, int key) {
    // Base Case: Tree is empty or end of path reached
    if (root == NULL) {
        return 0; // False
    }

    // Check if current node is the key
    if (root->data == key) {
        return 1; // True
    }

    // Recursive Search: If found in Left OR found in Right
    if (search(root->left, key) || search(root->right, key)) {
        return 1;
    }

    return 0; // Not found in this subtree
}

int main() {
    /*
     * Tree:
     *      10
     *     /  \
     *    20   30
     *   /
     *  40
     */
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);

    int key = 30;
    if (search(root, key))
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d NOT found in the tree.\n", key);

    key = 99;
    if (search(root, key))
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d NOT found in the tree.\n", key);

    return 0;
}

// Time Complexity: O(N) - Worst case visits all nodes
// Space Complexity: O(H)
