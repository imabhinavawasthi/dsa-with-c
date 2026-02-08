// File: 9_pq_2_4_tree.c
// Purpose: Priority Queue using 2-4 Tree (Conceptual)
// Author: Abhinav Awasthi

#include <stdio.h>

/*
 * Priority Queue using 2-4 Tree (or B-Tree)
 * 
 * 1. Insert(k):
 *    - Standard 2-4 Tree insertion.
 *    - O(log N) complexity.
 *    - Keeps tree perfectly balanced.
 * 
 * 2. DeleteMin():
 *    - The minimum element is always in the leftmost leaf node.
 *    - Traverse down from root via child[0] until a leaf is reached.
 *    - The first key in that leaf is the minimum.
 *    - Delete that key (handling underflow/merge standard B-Tree logic).
 * 
 * Comparison with Heaps:
 * - Binary Heap is usually preferred for PQ because 'findMin' is O(1).
 * - B-Tree 'findMin' is O(log N) because we must traverse to leaf.
 * - However, B-Trees are better for external memory (disk) PQs.
 */

int main() {
    printf("Conceptual Implementation of PQ using 2-4 Tree.\n\n");
    printf("Operation: Insert(key)\n");
    printf(" -> Uses 2-4 Tree Insert Logic (Split full nodes).\n");
    
    printf("Operation: ExtractMin()\n");
    printf(" -> Go to Leftmost Child recursively.\n");
    printf(" -> Min Item = Leftmost Leaf's 1st Key.\n");
    
    return 0;
}

// Time Complexity: Insert O(log N), DeleteMin O(log N)
// Space Complexity: O(N)
