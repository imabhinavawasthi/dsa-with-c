// File: 7_bst_inorder_predecessor.c
// Purpose: Find In-order Predecessor of a given node in BST
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

/*
 * In-order Predecessor: The largest value smaller than the given node.
 * Logic:
 * Case 1: Node has Left Subtree -> Predecessor is the Rightmost node in Left Subtree.
 * Case 2: Node has No Left Subtree -> Start from root, keep track of last node where we turned RIGHT.
 */
struct Node* getPredecessor(struct Node* root, struct Node* target) {
    // Case 1: Left subtree exists
    if (target->left != NULL) {
        struct Node* temp = target->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    // Case 2: No Left Subtree
    struct Node* predecessor = NULL;
    struct Node* current = root;
    
    while (current != target) {
        if (target->data > current->data) {
            predecessor = current; // Possible predecessor
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return predecessor;
}

int main() {
    /*
        BST:
             50
           /    \
         30      70
        /  \    /  \
       20  40  60  80
    */
    struct Node* root = NULL;
    root = insert(root, 50); insert(root, 30); insert(root, 70);
    insert(root, 20); insert(root, 40); insert(root, 60); insert(root, 80);

    struct Node* target = search(root, 60); // Leaf node
    struct Node* pred = getPredecessor(root, target);
    if (pred) printf("Predecessor of %d is %d\n", target->data, pred->data);
    else printf("Predecessor of %d is NULL\n", target->data);

    target = search(root, 50); // Root node
    pred = getPredecessor(root, target); // Max of left subtree (40)
    if (pred) printf("Predecessor of %d is %d\n", target->data, pred->data);

    return 0;
}

// Time Complexity: O(H) (H = Log N average)
// Space Complexity: O(1) Iterative
