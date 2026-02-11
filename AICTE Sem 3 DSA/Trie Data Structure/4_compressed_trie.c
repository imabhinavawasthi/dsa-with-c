/*
 * File: 4_compressed_trie.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates a Simplified Compressed Trie (Radix Tree/Patricia Trie).
 *
 * Concept:
 * In a standard Trie, chains of nodes with single children waste space.
 * E.g., "romane" -> r -> o -> m -> a -> n -> e (6 nodes).
 * Compressed Trie -> "romane" (1 node).
 *
 * Implementation (Simplified for Exam):
 * Instead of full string matching complexity, we will visualize the structure difference.
 * We will assume a standard Trie construction first, and then conceptually explain/show
 * how compression works or implement a basic string-edge node.
 * 
 * For this program:
 * We implement a slightly more advanced Node that holds a string 'label' instead of an array of pointers.
 * This is the core idea of Radix Tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LABEL 50
#define MAX_CHILDREN 10

// Compressed Trie Node
typedef struct RadixNode {
    char edgeLabel[MAX_LABEL];    // Store substring on the edge (e.g., "omane")
    struct RadixNode *children[MAX_CHILDREN];
    int childCount;
    bool isEndOfWord;
} RadixNode;

RadixNode *createNode(const char *label, bool isEnd) {
    RadixNode *node = (RadixNode *)malloc(sizeof(RadixNode));
    strcpy(node->edgeLabel, label);
    node->isEndOfWord = isEnd;
    node->childCount = 0;
    for(int i=0; i<MAX_CHILDREN; i++) node->children[i] = NULL;
    return node;
}

void insert(RadixNode *root, const char *word) {
    // Note: robust Radix Tree insertion is complex (requires edge splitting).
    // For exam purposes, we often just construct the tree manually to demonstrate the concept,
    // OR we implement a very specific case.
    
    // Here, we'll demonstrate manually building a compressed structure for specific words
    // to show the space saving concept compared to standard Trie.
    
    // Example: Insert "roman", "romanus", "romulus"
    // Standard Trie: r->o->m->a->n... (many nodes)
    // Compressed: root -> "rom" -> "an" -> "us"
    //                              -> "ulus"
    
    // Logic: This function is a placeholder. See main() for construction.
}

// DFS to display the Compressed Trie structure
void display(RadixNode *node, int level) {
    if (!node) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    
    printf("|-%s (%s)\n", node->edgeLabel, node->isEndOfWord ? "Word" : "");
    
    for (int i = 0; i < node->childCount; i++) {
        display(node->children[i], level + 1);
    }
}

int main() {
    printf("\n--- Compressed Trie (Radix Tree) / Concept Demo ---\n");

    // Root (Empty)
    RadixNode *root = createNode("", false);

    // 1. Insert "slow"
    // Root -> "slow"
    RadixNode *nodeSlow = createNode("slow", true);
    root->children[root->childCount++] = nodeSlow;

    // 2. Insert "slower"
    // Logic: "slow" share common prefix. Split? No, "slow" is prefix of "slower".
    // "slow" -> "er"
    RadixNode *nodeEr = createNode("er", true);
    nodeSlow->children[nodeSlow->childCount++] = nodeEr;

    // 3. Insert "slowly"
    // "slow" -> "ly"
    RadixNode *nodeLy = createNode("ly", true);
    nodeSlow->children[nodeSlow->childCount++] = nodeLy;

    // 4. Insert "water"
    RadixNode *nodeWater = createNode("water", true);
    root->children[root->childCount++] = nodeWater;
    
    // Display Structure
    printf("Structure Visualization:\n");
    display(root, 0);

    /* 
     Memory Comparison (Conceptual):
     
     Standard Trie for "slow", "slower", "slowly", "water":
     Nodes needed = 
     s-l-o-w (4)
     e-r (2)
     l-y (2)
     w-a-t-e-r (5)
     Total ~ 13+ nodes (plus root children arrays).
     
     Compressed Trie:
     Nodes = "slow", "er", "ly", "water" (4 nodes).
     
     Significant memory reduction!
    */
    printf("\n--- Comparison ---\n");
    printf("Standard Trie Nodes: ~14 nodes\n");
    printf("Compressed Trie Nodes: 4 nodes\n");
    printf("Advantage: Reduced memory overhead and fewer pointer traversals.\n");

    return 0;
}

// Time Complexity: O(K) where K is word length (traversal is faster due to fewer hops).
// Space Complexity: O(N) words. 
