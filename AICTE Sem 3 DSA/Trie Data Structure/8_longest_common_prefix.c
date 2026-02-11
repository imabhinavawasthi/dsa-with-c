/*
 * File: 8_longest_common_prefix.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds the Longest Common Prefix (LCP) of a set of strings using a Trie.
 *
 * Logic:
 * 1. Insert all strings into the Trie.
 * 2. Traverse from the root.
 * 3. Keep moving down as long as:
 *    - Current node has exactly ONE child.
 *    - Current node is NOT the end of a word.
 * 4. The path traversed is the Longest Common Prefix.
 *
 * Time Complexity: O(S), where S is the sum of all characters in all strings.
 * (Construction takes O(S) and traversal takes O(LCP length)).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int childCount; // Optimization: Track number of children
} TrieNode;

TrieNode *getNode(void) {
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (pNode) {
        pNode->isEndOfWord = false;
        pNode->childCount = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(TrieNode *root, const char *key) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
            pCrawl->childCount++;
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

// Function to find LCP
void findLCP(TrieNode *root, char *buffer) {
    TrieNode *pCrawl = root;
    int index = 0;

    // Traverse while node has exactly 1 child and is not end of a word
    while (pCrawl && pCrawl->childCount == 1 && !pCrawl->isEndOfWord) {
        // Find which child exists
        int nextIndex = -1;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (pCrawl->children[i]) {
                nextIndex = i;
                break;
            }
        }
        
        // Append character to buffer
        buffer[index++] = nextIndex + 'a';
        pCrawl = pCrawl->children[nextIndex];
    }
    buffer[index] = '\0';
}

int main() {
    TrieNode *root = getNode();

    char *arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insert(root, arr[i]);

    char lcp[100];
    findLCP(root, lcp);

    printf("\n--- Longest Common Prefix (Trie) ---\n");
    printf("Input Strings: ");
    for(int i=0; i<n; i++) printf("%s, ", arr[i]);
    
    if (strlen(lcp) > 0)
        printf("\n\nLongest Common Prefix: %s\n", lcp);
    else
        printf("\n\nNo Common Prefix found.\n");

    return 0;
}
