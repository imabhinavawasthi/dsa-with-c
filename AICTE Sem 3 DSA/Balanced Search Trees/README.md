# Balanced Search Trees Programs (C and C++)

This directory contains implementations for **AVL Trees** (Self-Balancing BST) and **2-4 Trees** (Multi-way Search Trees), along with conceptual introductions to **B-Trees** and **Priority Queues**.

Each program is provided in both **C (.c)** and **C++ (.cpp)** versions.
The C++ versions use explicit Classes/Pointers and **avoid STL** for exam compatibility.

## List of Programs

### A. AVL Trees (Self-Balancing)
1. **Insertion & Rotations**: `1_avl_insertion.c/cpp`
    - Implements LL, RR, LR, RL Rotations.
    - Updates heights and balance factors.
2. **Search Operation**: `2_avl_search.c/cpp`
    - Standard O(log N) search.
3. **Deletion**: `3_avl_deletion.c/cpp`
    - Deletes node and rebalances the tree upwards.
4. **AVL vs BST**: `4_bst_vs_avl.c/cpp`
    - Demonstrates how AVL maintains O(log N) height while BST degenerates to O(N).

### B. 2-4 Trees (Multi-way Trees)
5. **Structure & Search**: `5_2_4_tree_search.c/cpp`
    - Node structure with up to 3 keys and 4 children.
6. **Insertion**: `6_2_4_tree_insertion.c/cpp`
    - Simplified insertion logic handling node splitting.

### C. Advanced Concepts
7. **B-Tree Introduction**: `7_b_tree_intro.c/cpp`
    - Conceptual code explaining B-Trees as generic M-way trees.
8. **AVL Priority Queue**: `8_pq_avl.c/cpp`
    - Using AVL Tree for Priority Queue operations.
9. **2-4 Tree Priority Queue**: `9_pq_2_4_tree.c/cpp`
    - Conceptual model of PQ using Multi-way trees.

## How to Compile & Run
To run any C program:
```bash
gcc -o output filename.c
./output
```

To run any C++ program:
```bash
g++ -o output filename.cpp
./output
```
