// File: 1_avl_insertion.c
// Purpose: Implement AVL Tree Insertion with Rotations (LL, RR, LR, RL)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

/*
 * AVL Tree: A self-balancing Binary Search Tree.
 * Property: For every node, height difference (Balance Factor) between
 *           Left & Right Subtree is at most 1 (i.e., -1, 0, 1).
 * 
 * Rotations:
 * 1. LL Rotation (Right Rotation): Left Heavy
 * 2. RR Rotation (Left Rotation): Right Heavy
 * 3. LR Rotation: Left Heavy -> Right Child
 * 4. RL Rotation: Right Heavy -> Left Child
 */

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Helper: Get height of a node
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Helper: Max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node added at leaf has height 1
    return node;
}

// Calculate Balance Factor
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Right Rotation (LL Case)
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // New root
    return x;
}

// Left Rotation (RR Case)
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // New root
    return y;
}

// Recursive Insert Function
struct Node* insert(struct Node* node, int key) {
    /* 1. Normal BST Insertion */
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor */
    int balance = getBalance(node);

    /* 4. If unbalanced, then there are 4 cases */

    // Left Left Case (LL Rotation)
    if (balance > 1 && key < node->left->key) {
        printf("LL Rotation at Node %d\n", node->key);
        return rightRotate(node);
    }

    // Right Right Case (RR Rotation)
    if (balance < -1 && key > node->right->key) {
        printf("RR Rotation at Node %d\n", node->key);
        return leftRotate(node);
    }

    // Left Right Case (LR Rotation)
    if (balance > 1 && key > node->left->key) {
        printf("LR Rotation at Node %d\n", node->key);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (RL Rotation)
    if (balance < -1 && key < node->right->key) {
        printf("RL Rotation at Node %d\n", node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* 5. return the (unchanged) node pointer */
    return node;
}

void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    /* Constructing tree given in most specific examples */
    printf("Inserting 10, 20, 30... (Triggers RR Rotation)\n");
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("\nInserting 40, 50... (Triggers RR Rotation)\n");
    root = insert(root, 40);
    root = insert(root, 50);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("\nInserting 25... (Triggers RL Rotation)\n");
    root = insert(root, 25);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(log N) due to balancing
// Space Complexity: O(N)
