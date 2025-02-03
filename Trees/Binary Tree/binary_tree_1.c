#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    // root
    printf("%d ->", root->item);
    // left subtree
    preorderTraversal(root->left);
    // right subtree
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    // left subtree
    postorderTraversal(root->left);
    // right subtree
    postorderTraversal(root->right);
    // root
    printf("%d ->", root->item);
}

void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    // left subtree
    inorderTraversal(root->left);
    // root
    printf("%d ->", root->item);
    // right subtree
    inorderTraversal(root->right);
}

int main() {
    struct node* root = createNode(1);
    struct node* a = createNode(5);
    struct node* b = createNode(9);
    struct node* c = createNode(7);
    root->left = a;
    root->right = b;
    a->left=c;

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);

    printf("\nInorder traversal \n");
    inorderTraversal(root);
}