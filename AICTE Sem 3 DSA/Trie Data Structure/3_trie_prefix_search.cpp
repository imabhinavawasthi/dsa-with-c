/*
 * File: 3_trie_prefix_search.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements Autocomplete (Prefix Search) using a Trie in C++.
 *
 * Use Case:
 * Google search suggestions, IDE intellisense, Mobile keyboard suggestions.
 */

#include <iostream>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class AutocompleteTrie {
private:
    TrieNode *root;

    void printSuggestions(TrieNode *node, string currentPrefix) {
        if (node->isEndOfWord) {
            cout << currentPrefix << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                char nextChar = i + 'a';
                printSuggestions(node->children[i], currentPrefix + nextChar);
            }
        }
    }

public:
    AutocompleteTrie() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    void searchPrefix(string prefix) {
        TrieNode *pCrawl = root;
        
        // Traverse to end of prefix
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index]) {
                cout << "No suggestions found for prefix: " << prefix << endl;
                return;
            }
            pCrawl = pCrawl->children[index];
        }

        cout << "Suggestions for '" << prefix << "':" << endl;
        printSuggestions(pCrawl, prefix);
    }
};

int main() {
    AutocompleteTrie trie;

    // Dictionary
    trie.insert("struct");
    trie.insert("structure");
    trie.insert("strive");
    trie.insert("strychnine");
    trie.insert("student");
    trie.insert("study");
    trie.insert("learn");
    trie.insert("logic");

    cout << "\n--- Autocomplete System (C++) ---" << endl;

    trie.searchPrefix("stu");
    cout << endl;
    trie.searchPrefix("str");
    cout << endl;
    trie.searchPrefix("l");
    cout << endl;
    trie.searchPrefix("xyz"); // Not found

    return 0;
}
