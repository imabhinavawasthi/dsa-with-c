/*
 * File: 8_longest_common_prefix.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds the Longest Common Prefix (LCP) in an array of strings using a Trie.
 *
 * Example:
 * Input: {"apple", "ape", "april"}
 * Output: "ap"
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int childCount;

    TrieNode() {
        isEndOfWord = false;
        childCount = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = new TrieNode();
                pCrawl->childCount++;
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    string getLCP() {
        string lcp = "";
        TrieNode *pCrawl = root;

        // Loop until node has 1 child and is not end of word
        while (pCrawl && pCrawl->childCount == 1 && !pCrawl->isEndOfWord) {
            int index = -1;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (pCrawl->children[i]) {
                    index = i;
                    break;
                }
            }
            
            lcp += (char)(index + 'a');
            pCrawl = pCrawl->children[index];
        }
        return lcp;
    }
};

int main() {
    Trie t;
    vector<string> arr = {"apple", "ape", "april"};

    for (string s : arr) t.insert(s);

    cout << "\n--- Longest Common Prefix (C++) ---" << endl;
    cout << "Input: ";
    for (string s : arr) cout << s << " ";
    cout << endl;

    string lcp = t.getLCP();
    
    if (lcp.length() > 0)
        cout << "LCP: " << lcp << endl;
    else
        cout << "No Common Prefix." << endl;

    return 0;
}
