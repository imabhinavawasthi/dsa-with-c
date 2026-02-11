/*
 * File: 2_trie_map.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Trie-based Map (Dictionary) in C++.
 * Example Usage: Storing frequency of words.
 *
 * Key Feature:
 * - Each node can store an integer 'value'.
 * - If value != 0 (or some sentinel), it implies the end of a valid key.
 */

#include <iostream>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    int value; // 0 means key doesn't exist, >0 is the value

    TrieNode() {
        value = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class TrieMap {
private:
    TrieNode *root;

public:
    TrieMap() {
        root = new TrieNode();
    }

    // Insert or Update Key-Value pair
    void insert(string key, int val) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->value = val;
        cout << "Set Key: '" << key << "' = " << val << endl;
    }

    // Search and return value. Returns 0 if not found.
    int search(string key) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return 0;
            pCrawl = pCrawl->children[index];
        }
        return pCrawl->value;
    }
};

int main() {
    TrieMap map;

    cout << "\n--- Trie Map ADT (C++) ---" << endl;

    // Insert keys
    map.insert("hello", 1);
    map.insert("world", 2);
    map.insert("hell", 5); // Prefix of "hello"

    // Search
    cout << "\nSearching..." << endl;
    cout << "Value of 'hello': " << map.search("hello") << endl;
    cout << "Value of 'hell': " << map.search("hell") << endl;
    cout << "Value of 'world': " << map.search("world") << endl;
    
    // Non-existent key
    int val = map.search("hero");
    if (val == 0) cout << "'hero' not found." << endl;
    else cout << "Value of 'hero': " << val << endl;

    // Update
    cout << "\nUpdating 'hell' to 10..." << endl;
    map.insert("hell", 10);
    cout << "New Value of 'hell': " << map.search("hell") << endl;

    return 0;
}
