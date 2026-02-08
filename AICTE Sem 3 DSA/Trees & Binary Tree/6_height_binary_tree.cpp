// File: 6_height_binary_tree.cpp
// Purpose: Find height of a binary tree using Post-order Traversal logic
// Author: Abhinav Awasthi

#include <iostream>
#include <algorithm> // For max function
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find height
int findHeight(Node* root) {
    // Base Case
    if (root == NULL) {
        return 0;
    }

    // Recursive Step
    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);

    // Return larger height + 1
    // Using manual check instead of std::max if strictly no-STL logic desired, 
    // but algorithm header is usually allowed. 
    // I will write manual logic for clarity.
    if (leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

int main() {
    /*
     * Tree:
     *      10
     *        \
     *         20
     *           \
     *            30
     * Height: 3
     */
    Node* root = new Node(10);
    root->right = new Node(20);
    root->right->right = new Node(30);

    cout << "Height of the Tree: " << findHeight(root) << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(H) or O(N) worst case
