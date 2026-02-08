// File: 6_2_4_tree_insertion.cpp
// Purpose: Implement 2-4 Tree Insertion (Simplified Logic)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

#define MAX_KEYS 3

class Node {
public:
    int numKeys;
    int keys[MAX_KEYS];
    Node *children[MAX_KEYS + 1];
    Node *parent;
    bool isLeaf;

    Node(bool leaf) {
        numKeys = 0;
        isLeaf = leaf;
        parent = NULL;
        for (int i = 0; i <= MAX_KEYS; i++) children[i] = NULL;
    }
};

class MultiWayTree {
    Node *root;

    void splitChild(Node *parent, int childIndex, Node *child) {
        Node *newChild = new Node(child->isLeaf);
        newChild->numKeys = 1;
        newChild->keys[0] = child->keys[2]; // Take largest

        if (!child->isLeaf) {
            newChild->children[0] = child->children[2];
            newChild->children[1] = child->children[3];
        }

        child->numKeys = 1; // Keep smallest

        // Slide Parent children
        for (int i = parent->numKeys; i >= childIndex + 1; i--)
            parent->children[i + 1] = parent->children[i];
        
        parent->children[childIndex + 1] = newChild;
        newChild->parent = parent;

        // Slide keys
        for (int i = parent->numKeys - 1; i >= childIndex; i--)
            parent->keys[i + 1] = parent->keys[i];
        
        parent->keys[childIndex] = child->keys[1]; // Promote middle
        parent->numKeys++;
    }

    void insertNonFull(Node *node, int key) {
        int i = node->numKeys - 1;
        if (node->isLeaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            while (i >= 0 && key < node->keys[i]) i--;
            i++;
            if (node->children[i]->numKeys == 3) {
                splitChild(node, i, node->children[i]);
                if (key > node->keys[i]) i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

public:
    MultiWayTree() { root = NULL; }

    void insert(int key) {
        if (root == NULL) {
            root = new Node(true);
            root->keys[0] = key;
            root->numKeys = 1;
            return;
        }

        if (root->numKeys == 3) {
            Node *newRoot = new Node(false);
            newRoot->children[0] = root;
            root->parent = newRoot;
            splitChild(newRoot, 0, root);
            int i = 0;
            if (newRoot->keys[0] < key) i++;
            insertNonFull(newRoot->children[i], key);
            root = newRoot;
        } else {
            insertNonFull(root, key);
        }
        cout << "Inserted " << key << endl;
    }

    void printTree(Node *n, int level) {
        if (!n) return;
        cout << "L" << level << ": [ ";
        for (int i = 0; i < n->numKeys; i++) cout << n->keys[i] << " ";
        cout << "]" << endl;
        if (!n->isLeaf) {
            for (int i = 0; i <= n->numKeys; i++)
                printTree(n->children[i], level + 1);
        }
    }

    void display() {
        printTree(root, 0);
        cout << endl;
    }
};

int main() {
    MultiWayTree t;
    int data[] = {10, 20, 5, 6, 12, 30, 7};
    
    for (int x : data) {
        t.insert(x);
    }
    t.display();

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
