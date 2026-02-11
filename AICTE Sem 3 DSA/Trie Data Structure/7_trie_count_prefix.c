/*
 * File: 7_trie_count_prefix.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program counts the number of words in the Trie that start with a given prefix.
 *
 * Optimization:
 * Instead of traversing the whole subtree to count words (which is slow),
 * we verify the count by traversing to the end of the prefix and then
 * (A) performing a DFS to count leaf nodes (Standard Exam approach), OR
 * (B) maintaining a 'count' variable in each node during insertion (Optimized).
 *
 * Here, we implement METHOD A (DFS Traversal) as it is conceptually simpler
 * and reinforces recursion found in other Trie problems.
 *
 * Time Complexity: O(P + N), where P is prefix length and N is nodes in subtree.
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

// Recursive function to count leaf nodes (words) under a node
int countWords(TrieNode *root) {
    int count = 0;
    if (root->isEndOfWord)
        count++;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i])
            count += countWords(root->children[i]);
    }
    return count;
}

int getPrefixCount(TrieNode *root, const char *prefix) {
    TrieNode *pCrawl = root;
    
    // 1. Traverse to end of prefix
    for (int i = 0; i < strlen(prefix); i++) {
        int index = prefix[i] - 'a';
        if (!pCrawl->children[index])
            return 0; // Prefix not found
        pCrawl = pCrawl->children[index];
    }
    
    // 2. Count all words in the subtree of this node
    return countWords(pCrawl);
}

int main() {
    TrieNode *root = getNode();

    char *words[] = {"apple", "app", "apricot", "banana", "band", "bandana", "bat"};
    for (int i = 0; i < 7; i++) insert(root, words[i]);

    printf("\n--- Count Words with Prefix ---\n");
    printf("Dictionary: apple, app, apricot, banana, band, bandana, bat\n\n");

    char *prefixes[] = {"app", "ban", "ba", "z", "b"};
    
    for (int i = 0; i < 5; i++) {
        int count = getPrefixCount(root, prefixes[i]);
        printf("Prefix '%-3s': %d words found.\n", prefixes[i], count);
    }

    return 0;
}
