// File: 2_avl_search.c
// Purpose: Search for an element in an AVL Tree
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height; // AVL specific property
};

// Standard BST Search - Logic remains same for AVL
// Advantage: AVL guarantees O(log N) even in worst case
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;
    
    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);
    
    // Key is smaller than root's key
    return search(root->left, key);
}

// Minimal Logic for AVL Creation to test search
struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
// (Insertion/Rotation logic omitted for brevity in search focused file,
// usually you would include the full implementation)

int main() {
    // Creating a simple structure manually for search demo
    /*
          30
         /  \
       20    40
      /
     10
    */
    struct Node *root = createNode(30);
    root->left = createNode(20);
    root->right = createNode(40);
    root->left->left = createNode(10);

    int key = 20;
    if (search(root, key) != NULL)
        printf("Element %d found in AVL Tree.\n", key);
    else
        printf("Element %d NOT found.\n", key);

    return 0;
}

// Time Complexity: O(log N) (Guaranteed)
// Space Complexity: O(log N) Stack
