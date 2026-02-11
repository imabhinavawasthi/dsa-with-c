/*
 * File: 1_trie_basic.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Basic Trie (Prefix Tree) in C.
 *
 * What is a Trie?
 * A Trie is a tree-based data structure used for efficiently storing and retrieving keys in a dataset of strings.
 * The name comes from "ReTRIEval".
 *
 * Structure:
 * - Each node has an array of pointers (children) to subsequent characters.
 * - Commonly used for dictionaries, spell checkers, and prefix-based search.
 *
 * Operations Implemented:
 * 1. Insert: Add a word to the Trie.
 * 2. Search: Check if a word exists.
 * 3. Delete: Remove a word (Simple version).
 * 4. Display: Print all words in alphabetical order (DFS traversal).
 *
 * Time Complexity:
 * - Insert: O(L) where L is the length of the word.
 * - Search: O(L)
 * - Delete: O(L)
 * - Display: O(N * L) where N is total words.
 *
 * Space Complexity:
 * - O(N * L * ALPHABET_SIZE) in worst case (mostly sparse).
 *   This is higher than BST but provides faster lookup for strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Trie Node Structure
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord; // True if this node marks the end of a valid word
} TrieNode;

// Function Prototypes
TrieNode *getNode(void);
void insert(TrieNode *root, const char *key);
bool search(TrieNode *root, const char *key);
bool isEmpty(TrieNode *root);
TrieNode* deleteKey(TrieNode *root, const char *key, int depth);
void display(TrieNode *root, char str[], int level);

int main() {
    TrieNode *root = getNode();
    int choice;
    char word[100];

    while (1) {
        printf("\n--- Trie Data Structure (Basic) ---\n");
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("3. Delete Word\n");
        printf("4. Display All Words\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word to insert: ");
                scanf("%s", word);
                insert(root, word);
                break;
            case 2:
                printf("Enter word to search: ");
                scanf("%s", word);
                if (search(root, word))
                    printf("Found '%s' in Trie.\n", word);
                else
                    printf("'%s' NOT found in Trie.\n", word);
                break;
            case 3:
                printf("Enter word to delete: ");
                scanf("%s", word);
                root = deleteKey(root, word, 0);
                printf("Deleted '%s' (if it existed).\n", word);
                break;
            case 4:
                printf("Words in Trie:\n");
                char buffer[100];
                display(root, buffer, 0);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Create a new Trie Node
TrieNode *getNode(void) {
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));

    if (pNode) {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// Insert a word into the Trie
// Complexity: O(L)
void insert(TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;

    TrieNode *pCrawl = root;

    for (level = 0; level < length; level++) {
        // Calculate index (0 for 'a', 1 for 'b', etc.)
        index = key[level] - 'a'; 

        // Initial check for valid input (exam safety)
        if (index < 0 || index >= ALPHABET_SIZE) {
            printf("Invalid character '%c'. Only lowercase letters allowed.\n", key[level]);
            return;
        }

        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // Mark last node as leaf
    pCrawl->isEndOfWord = true;
    printf("Inserted: %s\n", key);
}

// Search for a word
// Complexity: O(L)
bool search(TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;
    TrieNode *pCrawl = root;

    for (level = 0; level < length; level++) {
        index = key[level] - 'a';

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    // Return true only if it's marked as end of word
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Helper to check if node has any children
bool isEmpty(TrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Global variable to track if deletion actually happened (optional, for feedback)
// For simplicity in exam, we just use recursive logic.

// Recursive function to delete a key
// Complexity: O(L)
TrieNode* deleteKey(TrieNode *root, const char *key, int depth) {
    // If tree is empty
    if (!root)
        return NULL;

    // If last character of key is being processed
    if (depth == strlen(key)) {
        // This node is no longer end of word after deletion
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // If given key is not prefix of any other word
        if (isEmpty(root)) {
            free(root);
            root = NULL;
        }
        return root;
    }

    // If not last character, recur for the child obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] = deleteKey(root->children[index], key, depth + 1);

    // If root does not have any child (its only child got deleted),
    // and it is not end of another word.
    if (isEmpty(root) && root->isEndOfWord == false) {
        free(root);
        root = NULL;
    }

    return root;
}

// Display all words (DFS Traversal)
// Prints words in alphabetical order
void display(TrieNode *root, char str[], int level) {
    // If node signifies end of word, print the accumulated string
    if (root->isEndOfWord) {
        str[level] = '\0';
        printf("%s\n", str);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        // If child exists, add char to buffer and recurse
        if (root->children[i]) {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

// Time Complexity:
// Insert, Search, Delete: O(L) where L is key length.
// Space Complexity: O(N * L) in worst case.
