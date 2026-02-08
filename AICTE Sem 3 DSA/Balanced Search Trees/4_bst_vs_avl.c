// File: 4_bst_vs_avl.c
// Purpose: Demonstrate Height Difference between BST and AVL
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

// --- AVL Node ---
struct AVLNode {
    int key;
    struct AVLNode *left, *right;
    int height;
};

// --- BST Node ---
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Helper Functions
int max(int a, int b) { return (a > b) ? a : b; }

// AVL Implementations
int avlHeight(struct AVLNode *N) {
    if (N == NULL) return 0;
    return N->height;
}

struct AVLNode* createAVLNode(int key) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode *rightRotate(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(avlHeight(y->left), avlHeight(y->right)) + 1;
    x->height = max(avlHeight(x->left), avlHeight(x->right)) + 1;
    return x;
}

struct AVLNode *leftRotate(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(avlHeight(x->left), avlHeight(x->right)) + 1;
    y->height = max(avlHeight(y->left), avlHeight(y->right)) + 1;
    return y;
}

int getBalance(struct AVLNode *N) {
    if (N == NULL) return 0;
    return avlHeight(N->left) - avlHeight(N->right);
}

struct AVLNode* insertAVL(struct AVLNode* node, int key) {
    if (node == NULL) return createAVLNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + max(avlHeight(node->left), avlHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// BST Implementations
struct BSTNode* createBSTNode(int key) {
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct BSTNode* insertBST(struct BSTNode* node, int key) {
    if (node == NULL) return createBSTNode(key);
    if (key < node->key) node->left = insertBST(node->left, key);
    else if (key > node->key) node->right = insertBST(node->right, key);
    return node;
}

int getBSTHeight(struct BSTNode* node) {
    if (node == NULL) return 0;
    int lh = getBSTHeight(node->left);
    int rh = getBSTHeight(node->right);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    struct AVLNode* avlRoot = NULL;
    struct BSTNode* bstRoot = NULL;

    // Inserting sorted data to create worst-case BST
    printf("Inserting numbers 1 to 10 in sorted order...\n");
    for (int i = 1; i <= 10; i++) {
        avlRoot = insertAVL(avlRoot, i);
        bstRoot = insertBST(bstRoot, i);
    }

    printf("\nHeight Comparison:\n");
    printf("BST Height (Expected 10): %d\n", getBSTHeight(bstRoot));
    printf("AVL Height (Expected ~4): %d\n", avlHeight(avlRoot));
    
    printf("\nConclusion:\n");
    printf("BST became Skewed (O(N) height).\n");
    printf("AVL remained Balanced (O(log N) height).\n");

    return 0;
}

// Time Complexity: AVL O(log N), BST O(N)
