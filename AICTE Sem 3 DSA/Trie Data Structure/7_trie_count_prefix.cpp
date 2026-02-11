/*
 * File: 7_trie_count_prefix.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program counts words with a given prefix using an OPTIMIZED Trie.
 *
 * Optimization:
 * We maintain a `prefixCount` variable in each node.
 * When inserting a word, we increment `prefixCount` for every node on the path.
 *
 * Result:
 * Prefix Count Query becomes O(P) (Prefix Length), independent of dictionary size.
 * This is extremely efficient.
 */

#include <iostream>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    int prefixCount; // Number of words sharing this prefix path
    bool isEndOfWord;

    TrieNode() {
        prefixCount = 0;
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class TriePrefixCounter {
private:
    TrieNode *root;

public:
    TriePrefixCounter() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode *pCrawl = root;
        pCrawl->prefixCount++; // Root count = total words

        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            
            pCrawl = pCrawl->children[index];
            pCrawl->prefixCount++; // Increment count on path
        }
        pCrawl->isEndOfWord = true;
    }

    int countPrefix(string prefix) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return 0; // Prefix doesn't exist
            pCrawl = pCrawl->children[index];
        }
        return pCrawl->prefixCount;
    }
};

int main() {
    TriePrefixCounter tpc;
    
    string words[] = {"code", "coder", "coding", "codability", "codex", "corn", "cool"};
    for (string w : words) tpc.insert(w);

    cout << "\n--- Count Prefix (Optimized O(L)) ---" << endl;
    cout << "Words inserted: code, coder, coding, codability, codex, corn, cool" << endl << endl;

    string prefixes[] = {"co", "cod", "code", "cor", "cool", "x"};

    for (string p : prefixes) {
        cout << "Prefix '" << p << "': " << tpc.countPrefix(p) << " words." << endl;
    }
    
    return 0;
}
