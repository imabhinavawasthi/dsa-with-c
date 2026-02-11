/*
 * File: 15_hash_vs_bst.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program conceptually compares Hash Tables and Binary Search Trees (BST).
 *
 * Complexity Analysis:
 * 
 * | Feature         | Hash Table                  | Balanced BST (AVL/Red-Black) |
 * |-----------------|-----------------------------|------------------------------|
 * | Search (Avg)    | O(1)                        | O(log n)                     |
 * | Insert (Avg)    | O(1)                        | O(log n)                     |
 * | Delete (Avg)    | O(1)                        | O(log n)                     |
 * | Range Query     | Poor (O(n))                 | Excellent (O(log n + k))     |
 * | Sorting         | Not Sorted                  | Naturally Sorted             |
 *
 */

#include <iostream>
using namespace std;

#define HASH_SIZE 20

class HashTable {
    int table[HASH_SIZE];
public:
    HashTable() {
        for (int i = 0; i < HASH_SIZE; i++) table[i] = -1;
    }
    
    void insert(int key) {
        int idx = key % HASH_SIZE;
        while (table[idx] != -1) idx = (idx + 1) % HASH_SIZE; // Linear probing
        table[idx] = key;
    }
    
    int searchSteps(int key) {
        int idx = key % HASH_SIZE;
        int steps = 1;
        while (table[idx] != -1) {
            if (table[idx] == key) return steps;
            idx = (idx + 1) % HASH_SIZE;
            steps++;
        }
        return steps;
    }
};

struct BSTNode {
    int key;
    BSTNode *left, *right;
    BSTNode(int k) : key(k), left(NULL), right(NULL) {}
};

class BST {
public:
    BSTNode* insert(BSTNode* root, int key) {
        if (!root) return new BSTNode(key);
        if (key < root->key) root->left = insert(root->left, key);
        else root->right = insert(root->right, key);
        return root;
    }
    
    int searchSteps(BSTNode* root, int key, int steps) {
        if (!root) return steps;
        if (root->key == key) return steps + 1;
        if (key < root->key) return searchSteps(root->left, key, steps + 1);
        else return searchSteps(root->right, key, steps + 1);
    }
};

int main() {
    HashTable ht;
    BST bst;
    BSTNode* root = NULL;
    
    int keys[] = {50, 30, 20, 40, 70, 60, 80}; // Optimal insertion level-orderish
    
    for (int k : keys) {
        ht.insert(k);
        root = bst.insert(root, k);
    }
    
    int target = 60;
    
    cout << "\n--- Comparison: Hash Table vs BST (C++) ---" << endl;
    cout << "Target Key: " << target << endl << endl;
    
    cout << "Hash Table Steps: " << ht.searchSteps(target) << " (O(1))" << endl;
    cout << "BST Search Steps: " << bst.searchSteps(root, target, 0) << " (O(log n))" << endl;
    
    cout << "\nSummary:" << endl;
    cout << "Hash Table found it faster (or comparable for small n) but offers O(1) generally." << endl;
    cout << "BST required traversal proportional to height (log n)." << endl;
    
    return 0;
}
