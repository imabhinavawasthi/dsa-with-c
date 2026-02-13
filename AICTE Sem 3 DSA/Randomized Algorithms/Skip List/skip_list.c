/*
  File: skip_list.c
  Title: Skip List Implementation
  Author: [Your Name]
  Date: [Current Date]

  Description:
  This program implements a Basic Skip List.
  Skip Lists are a probabilistic data structure that allows O(log N) search complexity, similar to Balanced BSTs (AVL, Red-Black).

  Skip List vs BST:
  - BSTs require complex rotation logic to stay balanced (e.g., AVL, Red-Black).
  - Skip Lists use randomization to achieve balance probabilistically.
  - Skip Lists are easier to implement and require no rotations.
  - Both have Expected Time Complexity of O(log N) for Search, Insert, Delete.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 3
#define P 0.5

// Node Structure
typedef struct Node {
    int key;
    struct Node **forward; // Array of pointers
} Node;

// Skip List Structure
typedef struct SkipList {
    int level;      // Current maximum level
    Node *header;   // Header node
} SkipList;

// Function to create a new node
Node* createNode(int key, int level) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    // Allocate memory for forward pointers (level + 1)
    n->forward = (Node **)malloc((level + 1) * sizeof(Node*));
    
    // Initialize pointers to NULL
    for (int i = 0; i <= level; i++) {
        n->forward[i] = NULL;
    }
    return n;
}

// Function to generate random level for a new node
int randomLevel() {
    int lvl = 0;
    // P is 0.5, so 50% chance to increase level
    while (((float)rand() / RAND_MAX) < P && lvl < MAX_LEVEL) {
        lvl++;
    }
    return lvl;
}

// Initialize Skip List
SkipList* createSkipList() {
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->level = 0;
    // Header key is -1 (or -Infinity), max possible level
    list->header = createNode(-1, MAX_LEVEL);
    return list;
}

// Function to insert a key
void insert(SkipList *list, int key) {
    Node *current = list->header;
    Node *update[MAX_LEVEL + 1]; // Array to store path

    // Start from top level and move down
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current; // Store pointer to node before insertion point
    }

    // Determine level for new node
    int lvl = randomLevel();

    // If new level is higher than current list level, update header links
    if (lvl > list->level) {
        for (int i = list->level + 1; i <= lvl; i++) {
            update[i] = list->header;
        }
        list->level = lvl;
    }

    // Create new node and link it
    Node *newNode = createNode(key, lvl);
    for (int i = 0; i <= lvl; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
    printf("Inserted %d at level %d\n", key, lvl);
}

// Function to display the skip list
void display(SkipList *list) {
    printf("\nSkip List Structure:\n");
    for (int i = 0; i <= list->level; i++) {
        Node *node = list->header->forward[i];
        printf("Level %d: ", i);
        while (node != NULL) {
            printf("%d -> ", node->key);
            node = node->forward[i];
        }
        printf("NULL\n");
    }
}

int main() {
    srand(time(NULL));

    SkipList *list = createSkipList();

    printf("=== Skip List Implementation ===\n");
    
    // Insert elements
    insert(list, 3);
    insert(list, 6);
    insert(list, 7);
    insert(list, 9);
    insert(list, 12);
    insert(list, 19);
    insert(list, 17);
    insert(list, 26);
    insert(list, 21);
    insert(list, 25);

    display(list);

    printf("\nComparison with BST:\n");
    printf("- In BST, inserting sorted data (3, 6, 7...) creates a skewed tree (O(N)).\n");
    printf("- In Skip List, randomization ensures balanced levels (O(log N)) even with sorted input.\n");
    printf("- No complex rotations needed here!\n");

    return 0;
}

/*
  // Worst Case Time Complexity: O(N) (Extremely rare)
  // Average / Expected Time Complexity: O(log N) for Search, Insert, Delete
  // Space Complexity: O(N) (Average pointers per node is 1/(1-P), typically 2)
*/
