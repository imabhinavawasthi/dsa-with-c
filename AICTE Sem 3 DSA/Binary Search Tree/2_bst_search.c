// File: 2_bst_search.c
// Purpose: Search for an element in a Binary Search Tree
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
 * Search Logic (Recursive):
 * 1. Base Case: If root is NULL or key is present at root, return root.
 * 2. If key < root->data: Search in Left Subtree.
 * 3. If key > root->data: Search in Right Subtree.
 * 
 * Unlike standard Binary Tree search (O(N)), BST Search is O(log N) average.
 */
struct Node* search(struct Node* root, int key) {
    // Base Case: Root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is smaller than root's key -> Search LEFT
    if (key < root->data) {
        return search(root->left, key);
    }

    // Key is larger than root's key -> Search RIGHT
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 60;
    if (search(root, key) != NULL)
        printf("Element %d found in BST.\n", key);
    else
        printf("Element %d NOT found in BST.\n", key);

    key = 90;
    if (search(root, key) != NULL)
        printf("Element %d found in BST.\n", key);
    else
        printf("Element %d NOT found in BST.\n", key);

    return 0;
}

// Time Complexity: O(log N) Average, O(N) Worst Case
// Space Complexity: O(N) Stack Space (Average O(log N))
