/*
 * File: 3_trie_prefix_search.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Prefix Search (Autocomplete) using a Trie.
 *
 * Goal: Given a prefix (e.g., "ca"), print all words in the dictionary starting with "ca"
 * (e.g., "cat", "cap", "cake", "camera").
 *
 * Logic:
 * 1. Traverse to the node representing the last character of the prefix.
 * 2. If valid path, perform DFS from that node.
 * 3. Print every complete word found during DFS.
 *
 * Why Trie is better than BST?
 * - Prefix search in Trie is O(P + S), where P=prefix length, S=output size.
 * - In BST, checking prefixes requires finding lower_bound and iterating, which is slower/more complex.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode *getNode(void) {
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (pNode) {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(TrieNode *root, const char *key) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

// Recursive function to print all words under a node
void printSuggestions(TrieNode *root, char buffer[], int level) {
    // If exact match found
    if (root->isEndOfWord) {
        buffer[level] = '\0';
        printf("%s\n", buffer);
    }

    // Recurse for all children
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            buffer[level] = i + 'a';
            printSuggestions(root->children[i], buffer, level + 1);
        }
    }
}

// Main function to initiate autocomplete
void autocomplete(TrieNode *root, const char *prefix) {
    TrieNode *pCrawl = root;
    int length = strlen(prefix);

    // 1. Traverse to the end of the prefix
    for (int i = 0; i < length; i++) {
        int index = prefix[i] - 'a';
        if (!pCrawl->children[index]) {
            printf("No words found with prefix '%s'\n", prefix);
            return;
        }
        pCrawl = pCrawl->children[index];
    }

    // 2. Perform DFS from this point
    printf("Suggestions for '%s':\n", prefix);
    
    // We need to pass the prefix itself to the recursive function
    // so it can print meaningful words.
    // Create a buffer and copy prefix into it.
    char buffer[100];
    strcpy(buffer, prefix);
    
    printSuggestions(pCrawl, buffer, length);
}

int main() {
    TrieNode *root = getNode();
    
    // Build Dictionary
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");

    printf("\n--- Trie Autocomplete Simulation ---\n");
    
    autocomplete(root, "hel");
    printf("\n");
    autocomplete(root, "c");
    printf("\n");
    autocomplete(root, "z");

    return 0;
}

// Time Complexity: O(P + TotalMatchingNodes)
// Space Complexity: O(L * N)
