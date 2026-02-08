// File: 8_bst_inorder_successor.c
// Purpose: Find In-order Successor of a given node in BST
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
 * In-order Successor: The smallest value greater than the given node.
 * Logic:
 * Case 1: Node has Right Subtree -> Successor is Leftmost node in Right Subtree.
 * Case 2: Node has No Right Subtree -> Start from Root, Successor is last node where we turned LEFT.
 */

struct Node* getSuccessor(struct Node* root, struct Node* target) {
    // Case 1: Right Subtree Exists
    if (target->right != NULL) {
        struct Node* temp = target->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    // Case 2: No Right Subtree -> Search from Root
    struct Node* successor = NULL;
    struct Node* current = root;
    while (current != target) {
        if (target->data < current->data) {
            successor = current; // Possible successor
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

int main() {
    /*
        BST:
             20
           /    \
         10      30
                   \
                    40
    */
    struct Node* root = NULL;
    root = insert(root, 20); insert(root, 10); insert(root, 30); insert(root, 40);

    struct Node* target = search(root, 20);
    struct Node* succ = getSuccessor(root, target);

    if (succ) printf("Successor of %d is %d\n", target->data, succ->data);
    else printf("Successor of %d is NULL\n", target->data);

    return 0;
}

// Time Complexity: O(H)
// Space Complexity: O(1) Iterative
