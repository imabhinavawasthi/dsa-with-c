// File: 10_bst_balance_factor.c
// Purpose: Compute Balance Factor (Height Diff) for each node
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * Balance Factor (BF):
 * BF = Height(Left Subtree) - Height(Right Subtree)
 * 
 * Importance:
 * In AVL Trees, BF must be -1, 0, or 1.
 * If |BF| > 1, the tree is Unbalanced (Skewed).
 * Rotations (LL, RR, LR, RL) are used to fix this.
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

int getHeight(struct Node* root) {
    if (root == NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int getBalanceFactor(struct Node* root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// In-order traversal to show BF for each node
void showBalanceFactors(struct Node* root) {
    if (root == NULL) return;
    
    showBalanceFactors(root->left);
    
    printf("Node: %d, Balance Factor: %d\n", root->data, getBalanceFactor(root));
    
    showBalanceFactors(root->right);
}

int main() {
    struct Node* root = NULL;
    
    // Creating an Unbalanced Tree (Left Heavy)
    //      30
    //     /
    //   20
    //   /
    // 10
    root = insert(root, 30);
    insert(root, 20);
    insert(root, 10);

    printf("Balance Factors (Left - Right):\n");
    showBalanceFactors(root); 
    // Node 30: Left H=2, Right H=0 -> BF = 2 (Unbalanced)
    
    return 0;
}

// Time Complexity: O(N^2) naive approach (calculating height repeatedly)
// Space Complexity: O(N)
