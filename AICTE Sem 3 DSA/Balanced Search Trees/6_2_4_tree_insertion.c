// File: 6_2_4_tree_insertion.c
// Purpose: Implement 2-4 Tree Insertion (Simplified Logic with Splitting)
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 3

struct Node {
    int numKeys;
    int keys[MAX_KEYS];
    struct Node *children[MAX_KEYS + 1];
    struct Node *parent; // Helpful for splitting
    bool isLeaf;
};

struct Node* createNode(bool isLeaf) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->numKeys = 0;
    node->isLeaf = isLeaf;
    node->parent = NULL;
    for (int i = 0; i < MAX_KEYS + 1; i++) node->children[i] = NULL;
    return node;
}

// Split a full child node (it will have 3 keys, we split into 1 and 1, push middle up)
// NOTE: This is a simplified "conceptual" demo for exams, not a fully robust generic B-Tree insert
void splitChild(struct Node *parent, int childIndex, struct Node *child) {
    struct Node *newChild = createNode(child->isLeaf);
    newChild->numKeys = 1; // It will take the largest key (originally at index 2)
    newChild->keys[0] = child->keys[2];

    // If not leaf, move the last two children to newChild
    if (!child->isLeaf) {
        newChild->children[0] = child->children[2];
        newChild->children[1] = child->children[3];
        if (newChild->children[0]) newChild->children[0]->parent = newChild;
        if (newChild->children[1]) newChild->children[1]->parent = newChild;
    }

    child->numKeys = 1; // Keeps only the smallest key (index 0)

    // Move children in parent to make room for newChild
    for (int i = parent->numKeys; i >= childIndex + 1; i--)
        parent->children[i + 1] = parent->children[i];
    
    parent->children[childIndex + 1] = newChild;
    newChild->parent = parent;

    // Move keys in parent to make room for promoted key
    // The promoted key is the middle one of the child (originally at index 1)
    for (int i = parent->numKeys - 1; i >= childIndex; i--)
        parent->keys[i + 1] = parent->keys[i];
    
    parent->keys[childIndex] = child->keys[1];
    parent->numKeys++;
}

void insertNonFull(struct Node *node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        // Find location and shift
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find child
        while (i >= 0 && key < node->keys[i])
            i--;
        i++; // Child index

        if (node->children[i]->numKeys == 3) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

struct Node* insert(struct Node *root, int key) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->numKeys = 1;
        return root;
    }

    if (root->numKeys == 3) {
        struct Node *newRoot = createNode(false);
        newRoot->children[0] = root;
        root->parent = newRoot;
        splitChild(newRoot, 0, root);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

void printTree(struct Node *root, int level) {
    if (root == NULL) return;
    printf("Level %d: [", level);
    for (int i = 0; i < root->numKeys; i++)
        printf("%d ", root->keys[i]);
    printf("]\n");

    if (!root->isLeaf) {
        for (int i = 0; i <= root->numKeys; i++)
            printTree(root->children[i], level + 1);
    }
}

int main() {
    struct Node *root = NULL;
    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
    // Expected behavior: Splitting when nodes fill up

    for (int i = 0; i < 8; i++) {
        printf("Inserting %d...\n", keys[i]);
        root = insert(root, keys[i]);
        printTree(root, 0);
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
