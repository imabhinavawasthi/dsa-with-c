/*
  File: skip_list.cpp
  Title: Skip List Implementation
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements a Basic Skip List.
  Skip Lists are a probabilistic data structure that allows O(log N) search complexity, similar to Balanced BSTs (AVL, Red-Black).
  
  Note: Manual memory management is used. No STL containers.

  Skip List vs BST:
  - BSTs require complex rotation logic to stay balanced (e.g., AVL, Red-Black).
  - Skip Lists use randomization to achieve balance probabilistically.
  - Skip Lists are easier to implement and require no rotations.
  - Both have Expected Time Complexity of O(log N) for Search, Insert, Delete.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_LEVEL = 3;
const float P = 0.5;

// Node Class
class Node {
public:
    int key;
    Node **forward; // Array of pointers

    Node(int key, int level) {
        this->key = key;
        // Allocate memory for forward pointers
        forward = new Node*[level + 1];
        
        // Initialize pointers to NULL
        for (int i = 0; i <= level; i++) {
            forward[i] = NULL;
        }
    }
    
    ~Node() {
        delete[] forward;
    }
};

// Skip List Class
class SkipList {
private:
    int level;      // Current maximum level
    Node *header;   // Header node

public:
    SkipList() {
        level = 0;
        // Header key is -1 (or -Infinity), max possible level
        header = new Node(-1, MAX_LEVEL);
    }
    
    // Helper to generate random level
    int randomLevel() {
        int lvl = 0;
        // P is 0.5, so 50% chance to increase level
        while (((float)rand() / RAND_MAX) < P && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }

    // Function to insert a key
    void insert(int key) {
        Node *current = header;
        Node *update[MAX_LEVEL + 1]; // Array to store path

        // Start from top level and move down
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != NULL && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current; // Store pointer to node before insertion point
        }

        // Determine level for new node
        int lvl = randomLevel();

        // If new level is higher than current list level, update header links
        if (lvl > level) {
            for (int i = level + 1; i <= lvl; i++) {
                update[i] = header;
            }
            level = lvl;
        }

        // Create new node and link it
        Node *newNode = new Node(key, lvl);
        for (int i = 0; i <= lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        cout << "Inserted " << key << " at level " << lvl << endl;
    }

    // Function to display the skip list
    void display() {
        cout << endl << "Skip List Structure:" << endl;
        for (int i = 0; i <= level; i++) {
            Node *node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != NULL) {
                cout << node->key << " -> ";
                node = node->forward[i];
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    srand(time(NULL));

    SkipList list;

    cout << "=== Skip List Implementation ===" << endl;
    
    // Insert elements
    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);

    list.display();

    cout << endl << "Comparison with BST:" << endl;
    cout << "- In BST, inserting sorted data (3, 6, 7...) creates a skewed tree (O(N))." << endl;
    cout << "- In Skip List, randomization ensures balanced levels (O(log N)) even with sorted input." << endl;
    cout << "- No complex rotations needed here!" << endl;

    return 0;
}

/*
  // Worst Case Time Complexity: O(N) (Extremely rare)
  // Average / Expected Time Complexity: O(log N) for Search, Insert, Delete
  // Space Complexity: O(N) (Average pointers per node is 1/(1-P), typically 2)
*/
