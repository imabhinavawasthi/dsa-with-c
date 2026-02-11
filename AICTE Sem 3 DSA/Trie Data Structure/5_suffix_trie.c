/*
 * File: 5_suffix_trie.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Suffix Trie.
 *
 * What is a Suffix Trie?
 * A Trie that stores ALL suffixes of a given text.
 *
 * Purpose:
 * Allows for checking if a pattern is a substring of the text in O(M) time,
 * where M is length of pattern.
 *
 * Construction (Naive for Exams):
 * 1. Generate all suffixes of the text.
 *    Example: "ban" -> "ban", "an", "n"
 * 2. Insert each suffix into a standard Trie.
 *
 * Time Complexity:
 * - Construction: O(N^2) in worst case (naive).
 * - Search: O(M) where M is pattern length.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfSuffix; // Marks end of a suffix
} TrieNode;

TrieNode *getNode(void) {
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (pNode) {
        pNode->isEndOfSuffix = false;
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
    pCrawl->isEndOfSuffix = true;
}

// Search for a Pattern (Substring)
// Since we inserted all suffixes, valid substring must be a prefix of some suffix.
bool search(TrieNode *root, const char *pattern) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < strlen(pattern); i++) {
        int index = pattern[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    // Unlike standard Trie search, we don't need isEndOfWord to be true.
    // Use Case: pattern "nana" in "banana"
    // Suffixes: banana, anana, nana, ana, na, a
    // "nana" path exists. Return true.
    return true;
}

int main() {
    TrieNode *root = getNode();
    char text[] = "banana";
    
    printf("\n--- Suffix Trie Implementation ---\n");
    printf("Text: %s\n", text);
    
    // 1. Construct Suffix Trie
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        // Insert suffix starting at i
        insert(root, &text[i]);
        printf("Inserted Suffix: %s\n", &text[i]);
    }
    
    // 2. Search Substrings
    char *patterns[] = {"nan", "ana", "ban", "xyz", "na"};
    int n_patterns = sizeof(patterns) / sizeof(patterns[0]);
    
    printf("\nSubstring Search Results:\n");
    for (int i = 0; i < n_patterns; i++) {
        if (search(root, patterns[i]))
            printf("'%s' is a substring.\n", patterns[i]);
        else
            printf("'%s' is NOT a substring.\n", patterns[i]);
    }

    return 0;
}

// Time Complexity: 
// Search: O(M) -> Very fast!
// Space Complexity: O(N^2) in worst case (Naive).
