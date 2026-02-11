/*
 * File: 15_hash_vs_bst.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates the difference between searching in a Hash Table vs a Binary Search Tree (BST).
 *
 * Concept:
 * 1. Hash Table:
 *    - Search Complexity: Average O(1).
 *    - Mechanism: Direct access using index = h(key).
 *    - Best for: Fast lookups, unsorted data.
 *    - Drawback: Probabilistic worst case O(n), no range queries.
 *
 * 2. Balanced BST (AVL/Red-Black):
 *    - Search Complexity: Guaranteed O(log n).
 *    - Mechanism: Traversing down the tree (left < root < right).
 *    - Best for: Range queries, sorted data processing.
 *    - Drawback: O(log n) is slower than O(1) for pure exact match.
 *
 * Implementation:
 * We insert elements into both structures and count "Steps" (Comparisons) to find a key.
 */

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 20

// --- Hash Table Implementation (Linear Probing) ---
int hashTable[HASH_SIZE];

void initHash() {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = -1; // -1 means empty
}

// Returns number of comparisons to find key
int searchHash(int key) {
    int index = key % HASH_SIZE;
    int steps = 1;
    
    // Linear Probe simulation
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) return steps;
        index = (index + 1) % HASH_SIZE;
        steps++;
    }
    return steps; // Not found
}

void insertHash(int key) {
    int index = key % HASH_SIZE;
    while (hashTable[index] != -1) {
        index = (index + 1) % HASH_SIZE;
    }
    hashTable[index] = key;
}

// --- BST Implementation ---
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key) root->left = insertBST(root->left, key);
    else if (key > root->key) root->right = insertBST(root->right, key);
    return root;
}

// Returns number of comparisons
int searchBST(Node* root, int key, int steps) {
    if (root == NULL) return steps;
    if (root->key == key) return steps + 1;
    
    if (key < root->key) return searchBST(root->left, key, steps + 1);
    else return searchBST(root->right, key, steps + 1);
}

int main() {
    // 1. Setup Hash Table
    initHash();
    int keys[] = {50, 30, 20, 40, 70, 60, 80}; // Balanced-ish insertion order for BST
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) insertHash(keys[i]);

    // 2. Setup BST
    Node* root = NULL;
    for (int i = 0; i < n; i++) root = insertBST(root, keys[i]);

    // 3. Compare Search
    int target = 60;
    
    printf("\n--- Comparison: Hash Table vs BST ---\n");
    printf("Searching for Key: %d\n\n", target);

    int hashSteps = searchHash(target);
    printf("Hash Table Search Steps: %d (O(1) expected)\n", hashSteps);

    int bstSteps = searchBST(root, target, 0);
    printf("BST Search Steps:        %d (O(log n) expected)\n", bstSteps);

    printf("\nCONCLUSION:\n");
    printf("1. Hash Tables are generally faster (O(1)) for exact matches.\n");
    printf("2. BSTs take O(log n) steps but keep data SORTED.\n");
    printf("3. Use Hash Tables for Caching/Dictionaries.\n");
    printf("4. Use BSTs for Range Queries (e.g., keys between 10 and 50).\n");

    return 0;
}
