/*
 * File: 2_trie_map.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Map ADT using a Trie.
 * Map: A collection of Key-Value pairs.
 * Key: String (Word)
 * Value: Integer (e.g., Frequency, ID, Score)
 *
 * Difference from Basic Trie:
 * - 'isEndOfWord' is replaced/augmented by 'value'.
 * - If 'value' != -1 (or 0), it marks end of word AND stores data.
 *
 * Operations:
 * 1. Insert(Key, Value): Update value if key exists.
 * 2. Search(Key): Return value if found, else -1.
 *
 * Time Complexity: O(L) for Insert and Search. Faster than Hash Table's worst case.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int value; // Replaces 'isEndOfWord'. -1 indicates no value.
} TrieNode;

TrieNode *getNode(void) {
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (pNode) {
        pNode->value = -1; // Initialize with -1 (meaning Key doesn't exist yet)
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(TrieNode *root, const char *key, int val) {
    int length = strlen(key);
    int index;
    TrieNode *pCrawl = root;

    for (int level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }

    // Assign value at leaf
    pCrawl->value = val;
    printf("Inserted Key: '%s' with Value: %d\n", key, val);
}

int search(TrieNode *root, const char *key) {
    int length = strlen(key);
    int index;
    TrieNode *pCrawl = root;

    for (int level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!pCrawl->children[index])
            return -1; // Path doesn't exist
        pCrawl = pCrawl->children[index];
    }

    return pCrawl->value; // Return stored value (-1 if key not marked as valid)
}

int main() {
    TrieNode *root = getNode();

    printf("\n--- Trie Map ADT (String -> Int) ---\n");

    // Scenario: Storing student marks or word frequencies
    insert(root, "apple", 100);
    insert(root, "app", 50);
    insert(root, "bat", 20);
    insert(root, "bath", 40);

    // Search Operations
    char *queries[] = {"apple", "app", "bat", "bath", "cat", "batman"};
    int n = sizeof(queries) / sizeof(queries[0]);

    printf("\nSearch Results:\n");
    for (int i = 0; i < n; i++) {
        int val = search(root, queries[i]);
        if (val != -1)
            printf("Key: '%-8s' -> Value: %d\n", queries[i], val);
        else
            printf("Key: '%-8s' -> Not Found\n", queries[i]);
    }

    // Update value
    printf("\nUpdating 'app' value to 75...\n");
    insert(root, "app", 75);
    printf("New Value for 'app': %d\n", search(root, "app"));

    return 0;
}

// Time Complexity: O(L)
// Space Complexity: O(N * L * 26)
