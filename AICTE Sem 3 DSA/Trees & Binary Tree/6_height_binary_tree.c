// File: 6_height_binary_tree.c
// Purpose: Find height of a binary tree using Post-order Traversal logic
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Height of Tree: Number of nodes on the longest path from root to leaf.
 * Logic (Recursive Post-order):
 * 1. Find height of Left Subtree
 * 2. Find height of Right Subtree
 * 3. Height = max(LeftHeight, RightHeight) + 1
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

// Function to find height
int findHeight(struct Node* root) {
    // Base Case: Empty tree has height 0
    if (root == NULL) {
        return 0;
    }

    // Recursive calls (Post-order nature: visit children first)
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Return max + 1
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    /*
     * Tree:
     *      1
     *     / \
     *    2   3
     *   / \
     *  4   5
     *       \
     *        6
     * Height should be 4 (Path: 1-2-5-6)
     */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->right = createNode(6); // Deepest node

    printf("Height of the Tree: %d\n", findHeight(root));

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H) (Stack Space)
