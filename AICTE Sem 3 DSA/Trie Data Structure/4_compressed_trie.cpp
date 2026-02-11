/*
 * File: 4_compressed_trie.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates the COMPRESSED TRIE (Radix Tree) concept in C++.
 *
 * Why Compressed Trie?
 * Standard Tries consume huge memory because each node contains an array of 26 pointers,
 * even if there's only one child.
 *
 * Optimization:
 * Merge nodes with single children into a single node holding a string edge.
 *
 * Exam Focus:
 * Full implementation is too complex for 10 marks.
 * This program constructs a sample Radix Tree to demonstrate the structure.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct RadixNode {
    string edgeLabel;
    bool isEndOfWord;
    vector<RadixNode*> children;

    RadixNode(string label, bool isEnd) {
        edgeLabel = label;
        isEndOfWord = isEnd;
    }
};

class RadixTree {
public:
    RadixNode *root;

    RadixTree() {
        root = new RadixNode("", false);
    }

    // Manual construction for demonstration
    // "test", "team", "toast"
    // t -> e -> s -> t
    //        -> a -> m
    //   -> o -> a -> s -> t
    //
    // Compressed:
    // t -> e -> st  (st merged)
    //        -> am  (am merged)
    //   -> oast     (oast merged)
    void buildDemo() {
        // Edge 't'
        RadixNode *t = new RadixNode("t", false);
        root->children.push_back(t);

        // Child 'e'
        RadixNode *e = new RadixNode("e", false);
        t->children.push_back(e);

        // Children of 'e'
        e->children.push_back(new RadixNode("st", true)); // test
        e->children.push_back(new RadixNode("am", true)); // team

        // Child 'oast' from 't'
        t->children.push_back(new RadixNode("oast", true)); // toast
    }

    void display(RadixNode *node, int level) {
        if (!node) return;
        
        for(int i=0; i<level; i++) cout << "  ";
        cout << "|- " << node->edgeLabel << (node->isEndOfWord ? " *" : "") << endl;

        for (auto child : node->children) {
            display(child, level + 1);
        }
    }
};

int main() {
    RadixTree tree;
    tree.buildDemo();

    cout << "\n--- Compressed Trie Visualization (C++) ---" << endl;
    cout << "Words: test, team, toast" << endl;
    cout << "* marks end of word" << endl << endl;
    
    tree.display(tree.root, 0);

    cout << "\n--- Analysis ---\n";
    cout << "Standard Trie Depth for 'toast': 5 nodes deep." << endl;
    cout << "Compressed Trie Depth for 'toast': 2 hops (root->t->oast)." << endl;
    cout << "Space Saved: Merged 'o-a-s-t' into 1 string node." << endl;

    return 0;
}
