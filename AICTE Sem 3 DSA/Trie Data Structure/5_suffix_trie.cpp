/*
 * File: 5_suffix_trie.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Suffix Trie in C++.
 *
 * Algorithm:
 * For a string S of length N, we insert all N suffixes into the Trie.
 *
 * Applications:
 * - Substring check
 * - Longest Repeated Substring
 * - Longest Common Substring
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfSuffix;

    TrieNode() {
        isEndOfSuffix = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class SuffixTrie {
private:
    TrieNode *root;

public:
    SuffixTrie(string text) {
        root = new TrieNode();
        // Construct Trie with all suffixes
        for (int i = 0; i < text.length(); i++) {
            insert(text.substr(i));
        }
    }

    void insert(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfSuffix = true;
    }

    bool isSubstring(string pattern) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < pattern.length(); i++) {
            int index = pattern[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return true; // Path exists means pattern is a prefix of some suffix -> Substring
    }
};

int main() {
    string text = "mississippi";
    cout << "\n--- Suffix Trie (C++) ---" << endl;
    cout << "Text: " << text << endl;

    SuffixTrie st(text);

    string patterns[] = {"is", "sip", "ppi", "miss", "river"};

    cout << "\nChecking Patterns:" << endl;
    for (string pat : patterns) {
        if (st.isSubstring(pat))
            cout << "'" << pat << "' FOUND." << endl;
        else
            cout << "'" << pat << "' NOT FOUND." << endl;
    }

    return 0;
}
