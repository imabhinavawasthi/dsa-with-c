// File: 5_2_4_tree_search.cpp
// Purpose: Implement 2-4 Tree Node Structure and Search
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

#define MAX_KEYS 3
#define MAX_CHILDREN 4

class Node {
public:
    int numKeys;
    int keys[MAX_KEYS];
    Node *children[MAX_CHILDREN];
    bool isLeaf;

    Node(bool leaf) {
        numKeys = 0;
        isLeaf = leaf;
        for (int i = 0; i < MAX_CHILDREN; i++)
            children[i] = NULL;
    }
};

Node* search(Node* root, int key) {
    int i = 0;
    // Find first key >= key
    while (i < root->numKeys && key > root->keys[i])
        i++;

    // Found?
    if (i < root->numKeys && root->keys[i] == key)
        return root;

    // Leaf?
    if (root->isLeaf)
        return NULL;

    // Recurse
    return search(root->children[i], key);
}

int main() {
    Node *root = new Node(false);
    root->numKeys = 1;
    root->keys[0] = 20;

    root->children[0] = new Node(true);
    root->children[0]->numKeys = 1;
    root->children[0]->keys[0] = 10;

    root->children[1] = new Node(true);
    root->children[1]->numKeys = 2;
    root->children[1]->keys[0] = 30;
    root->children[1]->keys[1] = 40;

    int key = 40;
    if (search(root, key))
        cout << "Found " << key << endl;
    else
        cout << "Not Found " << key << endl;

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(log N)
