// File: 4_bst_vs_avl.cpp
// Purpose: Height Comparison: Unbalanced BST vs AVL Tree
// Author: Abhinav Awasthi

#include <iostream>
#include <algorithm>
using namespace std;

// AVL
class AVLNode {
public:
    int key;
    AVLNode *left, *right;
    int height;
    AVLNode(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

int avlHeight(AVLNode *N) {
    if (N == NULL) return 0;
    return N->height;
}

AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(avlHeight(y->left), avlHeight(y->right)) + 1;
    x->height = max(avlHeight(x->left), avlHeight(x->right)) + 1;
    return x;
}

AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(avlHeight(x->left), avlHeight(x->right)) + 1;
    y->height = max(avlHeight(y->left), avlHeight(y->right)) + 1;
    return y;
}

int getBalance(AVLNode *N) {
    if (N == NULL) return 0;
    return avlHeight(N->left) - avlHeight(N->right);
}

AVLNode* insertAVL(AVLNode* node, int key) {
    if (node == NULL) return new AVLNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + max(avlHeight(node->left), avlHeight(node->right));
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

// BST
class BSTNode {
public:
    int key;
    BSTNode *left, *right;
    BSTNode(int k) : key(k), left(NULL), right(NULL) {}
};

BSTNode* insertBST(BSTNode* node, int key) {
    if (node == NULL) return new BSTNode(key);
    if (key < node->key) node->left = insertBST(node->left, key);
    else if (key > node->key) node->right = insertBST(node->right, key);
    return node;
}

int getBSTHeight(BSTNode* node) {
    if (node == NULL) return 0;
    return 1 + max(getBSTHeight(node->left), getBSTHeight(node->right));
}

int main() {
    AVLNode* avlRoot = NULL;
    BSTNode* bstRoot = NULL;

    cout << "Inserting 1 to 10..." << endl;
    for (int i = 1; i <= 10; i++) {
        avlRoot = insertAVL(avlRoot, i);
        bstRoot = insertBST(bstRoot, i);
    }

    cout << "BST Height: " << getBSTHeight(bstRoot) << endl;
    cout << "AVL Height: " << avlHeight(avlRoot) << endl;

    return 0;
}

// Time Complexity: AVL O(log N), BST O(N)
