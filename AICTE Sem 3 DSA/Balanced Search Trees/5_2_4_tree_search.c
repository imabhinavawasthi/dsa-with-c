// File: 5_2_4_tree_search.c
// Purpose: Implement 2-4 Tree Node Structure and Search
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 3 // A node can have at most 3 keys
#define MAX_CHILDREN 4 // A node can have at most 4 children

/*
 * 2-4 Tree Properties:
 * 1. Every node has at most 4 children.
 * 2. Every node has key count K, and K+1 children.
 * 3. All leaves are at the same depth.
 * 4. Perfectly Balanced.
 */

struct Node {
    int numKeys;
    int keys[MAX_KEYS]; // Stores up to 3 keys
    struct Node *children[MAX_CHILDREN]; // Stores up to 4 children
    bool isLeaf;
};

struct Node* createNode(bool isLeaf) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->numKeys = 0;
    node->isLeaf = isLeaf;
    for (int i = 0; i < MAX_CHILDREN; i++)
        node->children[i] = NULL;
    return node;
}

// Search Function
struct Node* search(struct Node* root, int key) {
    int i = 0;
    
    /* 1. Find the first key greater than or equal to k */
    while (i < root->numKeys && key > root->keys[i])
        i++;

    /* 2. If the found key is equal to k, return this node */
    if (i < root->numKeys && root->keys[i] == key)
        return root;

    /* 3. If key is not found here and this is a leaf node */
    if (root->isLeaf)
        return NULL;

    /* 4. Go to the appropriate child */
    return search(root->children[i], key);
}

// Minimal manual construction to test search
int main() {
    // Manually creating a small 2-4 Tree
    /*
             [ 20 ]
            /      \
      [ 10 ]     [ 30, 40 ]
    */
    struct Node *root = createNode(false);
    root->numKeys = 1;
    root->keys[0] = 20;

    struct Node *child1 = createNode(true);
    child1->numKeys = 1;
    child1->keys[0] = 10;

    struct Node *child2 = createNode(true);
    child2->numKeys = 2;
    child2->keys[0] = 30;
    child2->keys[1] = 40;

    root->children[0] = child1;
    root->children[1] = child2;

    int key = 30;
    if (search(root, key))
        printf("Found %d in 2-4 Tree.\n", key);
    else
        printf("Did not find %d.\n", key);

    return 0;
}

// Time Complexity: O(log N) - Height of tree is logarithmic base 4
// Space Complexity: O(log N) - Stack depth
