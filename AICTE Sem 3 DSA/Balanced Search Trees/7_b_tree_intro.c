// File: 7_b_tree_intro.c
// Purpose: Introduction to B-Trees (Conceptual)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * B-TREE CONCEPT:
 * A B-Tree is a self-balancing search tree that generalizes the BST and 2-4 Tree.
 * It is optimized for systems that read and write large blocks of data (Databases, File Systems).
 * 
 * Properties of a B-Tree of order 'm':
 * 1. Every node has at most 'm' children.
 * 2. Every node (except root) has at least ceil(m/2) children.
 * 3. The root has at least 2 children if it is not a leaf.
 * 4. A non-leaf node with k children contains k-1 keys.
 * 5. All leaves appear in the same level.
 * 
 * 2-4 Tree vs B-Tree:
 * - A 2-4 Tree is simply a B-Tree of order 4 (max 4 children, max 3 keys).
 * - B-Trees allows for much larger orders (e.g., m = 1000), which reduces height significantly.
 * 
 * Why Use B-Trees?
 * - Disk Access is slow. B-Trees minimize height (Log_m N), reducing disk I/O operations.
 */

// B-Tree Node Structure (Generalized)
struct BTreeNode {
    int *keys;          // Array of keys
    int t;              // Minimum degree (defines the range for number of keys)
    struct BTreeNode **C; // Array of child pointers
    int n;              // Current number of keys
    bool leaf;          // True if leaf node
};

// Function to create a B-Tree Node
struct BTreeNode* createNode(int t, bool leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->t = t;
    newNode->leaf = leaf;

    // Allocate memory for maximum possible keys (2*t - 1)
    newNode->keys = (int*)malloc(sizeof(int) * (2 * t - 1));

    // Allocate memory for maximum possible children (2*t)
    newNode->C = (struct BTreeNode**)malloc(sizeof(struct BTreeNode*) * (2 * t));

    newNode->n = 0; // Initially 0 keys
    return newNode;
}

// Example usage
int main() {
    int t = 3; // Minimum degree 3 (Max keys = 5, Max children = 6)
    
    struct BTreeNode *root = createNode(t, true);
    root->keys[0] = 10;
    root->n = 1;

    printf("Created a B-Tree Node with Minimum Degree t = %d\n", t);
    printf("Max Keys per Node = %d\n", 2 * t - 1);
    printf("Max Children per Node = %d\n", 2 * t);
    printf("Root Key: %d\n", root->keys[0]);

    return 0;
}

// Time Complexity: Search/Insert/Delete involves O(log_t N)
// Space Complexity: O(N)
