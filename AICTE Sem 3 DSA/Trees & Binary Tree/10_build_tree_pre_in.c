// File: 10_build_tree_pre_in.c
// Purpose: Construct Binary Tree from In-order and Pre-order Traversals
// Author: Abhinav Awasthi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find index of value in in[]
int search(char arr[], int start, int end, char value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
/*
 * Logic:
 * 1. Pick current node from Pre-order traversal using preIndex.
 * 2. Increment preIndex.
 * 3. Find this node in In-order traversal (inIndex).
 * 4. Elements before inIndex in in[] are Left Subtree.
 * 5. Elements after inIndex in in[] are Right Subtree.
 */
struct Node* buildTree(char in[], char pre[], int inStart, int inEnd, int* preIndex) {
    // Base Case
    if (inStart > inEnd) {
        return NULL;
    }

    // Pick current node from Preorder using pointer to maintain state across calls
    struct Node* tNode = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If this node has no children, return it
    if (inStart == inEnd) {
        return tNode;
    }

    // Else find index of this node in Inorder traversal
    int inIndex = search(in, inStart, inEnd, tNode->data);

    // Using index in Inorder traversal, construct left and right subtrees
    tNode->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    int preIndex = 0;

    printf("In-order:  D B E A F C\n");
    printf("Pre-order: A B D E C F\n");

    struct Node* root = buildTree(in, pre, 0, len - 1, &preIndex);

    printf("\nConstructed Tree (In-order Verification): ");
    printInorder(root);
    printf("\n");

    return 0;
}

// Time Complexity: O(N^2) due to searching in linear array. O(N) with Hash Map.
// Space Complexity: O(N)
