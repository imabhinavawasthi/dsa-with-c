/*
 * File: 6_trie_spell_checker.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a simple Spell Checker using a Trie.
 *
 * Logic:
 * 1. Load a dictionary of valid words into the Trie.
 * 2. Take an input word from the user.
 * 3. Search for it in the Trie.
 * 4. If found -> "Correct Speling".
 * 5. If not found -> "Misspelled".
 *
 * Why Trie?
 * Checking a word of length L takes O(L) time, independent of dictionary size.
 * This is much faster than linear search O(N*L) or even Binary Search O(L*log N).
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

bool search(TrieNode *root, const char *key) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    TrieNode *root = getNode();

    // 1. Load Dictionary (Small set for exam demo)
    char *dictionary[] = {"apple", "banana", "grape", "mango", "orange", 
                          "peach", "pear", "pineapple", "strawberry", "watermelon"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < n; i++) 
        insert(root, dictionary[i]);

    printf("\n--- Trie Spell Checker ---\n");
    printf("Dictionary Loaded with %d words.\n", n);

    // 2. Check Words
    char *inputs[] = {"apple", "apply", "ban", "banana", "grape", "grap"};
    
    printf("\nChecking Spelling:\n");
    for (int i = 0; i < 6; i++) {
        if (search(root, inputs[i])) {
            printf("%-10s : CORRECT\n", inputs[i]);
        } else {
            printf("%-10s : MISSPELLED (or unknown)\n", inputs[i]);
        }
    }

    return 0;
}

// Time Complexity: O(L) per word check.
