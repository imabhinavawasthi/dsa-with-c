/*
 * File: 6_trie_spell_checker.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Spell Checker using a Trie in C++.
 *
 * Efficiency:
 * For a dictionary with 1,000,000 words, checking a word like "hello"
 * takes only 5 steps (L=5). It is extremely fast.
 */

#include <iostream>
#include <string>
#include <vector>
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

class SpellChecker {
private:
    TrieNode *root;

public:
    SpellChecker() {
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

    bool check(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != NULL && pCrawl->isEndOfWord);
    }
};

int main() {
    SpellChecker sc;
    
    // Load Dictionary
    vector<string> dict = {"code", "coder", "coding", "program", "programming", "bug", "debug"};
    for (string word : dict) sc.insert(word);

    cout << "\n--- Spell Checker (C++) ---" << endl;
    cout << "Dictionary loaded." << endl;

    string inputs[] = {"code", "cod", "coding", "pro", "program", "debug", "de"};
    
    cout << "\nResults:" << endl;
    for (string word : inputs) {
        if (sc.check(word))
            cout << word << ": Valid" << endl;
        else
            cout << word << ": Invalid" << endl;
    }

    return 0;
}
