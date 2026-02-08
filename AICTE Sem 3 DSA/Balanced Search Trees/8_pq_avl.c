// File: 8_pq_avl.c
// Purpose: Implement Priority Queue using AVL Tree
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

// Reuse AVL Node logic
struct Node {
    int key; // Priority (Lower value = Higher Priority)
    struct Node *left, *right;
    int height;
};

// ... Include standard AVL Insert/Rotate/Height/Balance functions here ...
// For brevity in this PQ focus, minimal implementations are shown below
// In a real exam, you would write the full AVL insert logic.

int height(struct Node *N) { return (N == NULL) ? 0 : N->height; }
int max(int a, int b) { return (a > b) ? a : b; }

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return createNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
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

// Function to find Minimum Value Node (Highest Priority)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// PQ Operations
struct Node* deleteMin(struct Node* root, int* deletedKey) {
    if (root == NULL) return NULL;

    // Find min node (leftmost)
    struct Node* minNode = minValueNode(root);
    *deletedKey = minNode->key;

    // Standard AVL delete for this key
    // (Using a simplify delete wrapper or just reuse the general delete logic)
    // For this example assuming a general deleteAVL function handles it.
    // In simpler terms for exam: "We extract the min, then delete it from AVL"
    return root; // Placeholder return, actual deletion requires full delete logic
                  // Refer to File 3_avl_deletion.c for full delete code.
}

int main() {
    struct Node *pq = NULL;
    pq = insert(pq, 20);
    pq = insert(pq, 10);
    pq = insert(pq, 30);
    pq = insert(pq, 5); // Highest Priority

    // Logic: In a BST/AVL, the minimum element is always the leftmost node.
    // getMin() is O(log N). extractMin() is O(log N).
    
    struct Node* min = minValueNode(pq);
    if (min) printf("Highest Priority Element: %d\n", min->key);

    return 0;
}

// Time Complexity: Insert O(log N), ExtractMin O(log N)
// Space Complexity: O(N)
