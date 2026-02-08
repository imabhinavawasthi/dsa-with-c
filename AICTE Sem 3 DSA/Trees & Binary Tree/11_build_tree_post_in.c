// File: 11_build_tree_post_in.c
// Purpose: Construct Binary Tree from In-order and Post-order Traversals
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

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

/*
 * Logic for Post-order Construction:
 * 1. Post-order: [Left Child, Right Child, ROOT]
 * 2. So, traverse Post-order from END to START.
 * 3. The last element is Root. Second last is Right Child of Root (if exists).
 * 4. Important: Build Right Subtree BEFORE Left Subtree.
 */

struct Node* buildTree(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    // Base Case
    if (inStart > inEnd) {
        return NULL;
    }

    // Pick current node from Postorder (using postIndex which starts from end)
    struct Node* tNode = createNode(post[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) {
        return tNode;
    }

    // Find index in Inorder
    int inIndex = search(in, inStart, inEnd, tNode->data);

    // Build Right Subtree FIRST, then Left Subtree
    tNode->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    tNode->left = buildTree(in, post, inStart, inIndex - 1, postIndex);

    return tNode;
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int len = sizeof(in) / sizeof(in[0]);
    int postIndex = len - 1; // Start from last element

    printf("In-order:   4 8 2 5 1 6 3 7\n");
    printf("Post-order: 8 4 5 2 6 7 3 1\n");

    struct Node* root = buildTree(in, post, 0, len - 1, &postIndex);

    printf("Constructed Tree (Pre-order Verification): ");
    printPreorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)
