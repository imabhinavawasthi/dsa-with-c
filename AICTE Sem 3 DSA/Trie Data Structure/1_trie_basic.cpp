/*
 * File: 1_trie_basic.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Basic Trie (Prefix Tree) in C++.
 * NO STL used. We use manual memory management with new/delete.
 *
 * Class Structure:
 * - TrieNode: struct with array of pointers and boolean flag.
 * - Trie: Class encapsulating the root and operations.
 *
 * Operations:
 * 1. Insert: O(L)
 * 2. Search: O(L)
 * 3. Delete: O(L)
 * 4. Display: O(N*L) - Prints words in alphabetical order.
 */

#include <iostream>
#include <cstring>
using namespace std;

#define ALPHABET_SIZE 26

// Trie Node Structure
struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class Trie {
private:
    TrieNode *root;

    // Helper for Destructor
    void clear(TrieNode *node) {
        if (!node) return;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            clear(node->children[i]);
        }
        delete node;
    }

    // Helper for Display
    bool isEmpty(TrieNode *node) {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (node->children[i])
                return false;
        return true;
    }

    // Recursive Delete Helper
    TrieNode* remove(TrieNode *node, string key, int depth) {
        if (!node) return NULL;

        // If last character of key is being processed
        if (depth == key.length()) {
            if (node->isEndOfWord)
                node->isEndOfWord = false;

            if (isEmpty(node)) {
                delete node;
                node = NULL;
            }
            return node;
        }

        int index = key[depth] - 'a';
        node->children[index] = remove(node->children[index], key, depth + 1);

        if (isEmpty(node) && !node->isEndOfWord) {
            delete node;
            node = NULL;
        }
        return node;
    }

    // Recursive Display Helper
    void printWords(TrieNode *node, char buffer[], int level) {
        if (node->isEndOfWord) {
            buffer[level] = '\0';
            cout << buffer << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                buffer[level] = i + 'a';
                printWords(node->children[i], buffer, level + 1);
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void insert(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (index < 0 || index >= ALPHABET_SIZE) {
                cout << "Invalid character: " << key[i] << endl;
                return;
            }
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
        cout << "Inserted: " << key << endl;
    }

    bool search(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != NULL && pCrawl->isEndOfWord);
    }

    void deleteKey(string key) {
        root = remove(root, key, 0);
        cout << "Deleted '" << key << "' (if present)." << endl;
    }

    void display() {
        char buffer[100];
        printWords(root, buffer, 0);
    }
};

int main() {
    Trie t;
    int choice;
    string word;

    while (true) {
        cout << "\n--- Trie Data Structure (C++) ---" << endl;
        cout << "1. Insert Word" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. Delete Word" << endl;
        cout << "4. Display All Words" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                t.insert(word);
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                if (t.search(word))
                    cout << "Found '" << word << "' in Trie." << endl;
                else
                    cout << "'" << word << "' NOT found in Trie." << endl;
                break;
            case 3:
                cout << "Enter word to delete: ";
                cin >> word;
                t.deleteKey(word);
                break;
            case 4:
                cout << "Words in Trie:" << endl;
                t.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
