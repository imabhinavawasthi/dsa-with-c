# Binary Search Tree (BST) Programs (C and C++)

This directory contains simple, exam-oriented implementations of Binary Search Tree (BST) operations.

Each program is provided in both **C (.c)** and **C++ (.cpp)** versions.
The C++ versions use Classes and `new`/`delete` but **avoid STL** for exam compatibility.

## List of Programs

### A. Basic BST Operations
1. **Insert & Create**: `1_bst_insert.c/cpp`
    - Logic for inserting nodes into a BST.
2. **Search Element**: `2_bst_search.c/cpp`
    - Recursive search with O(log N) average complexity.
3. **In-order Traversal**: `3_bst_inorder.c/cpp`
    - **Important**: Produces sorted output for BSTs.
4. **Pre-order Traversal**: `4_bst_preorder.c/cpp`
5. **Post-order Traversal**: `5_bst_postorder.c/cpp`

### B. BST Structure & Worst Case
6. **Skewed BST Creation**: `6_bst_skewed_creation.c/cpp`
    - Demonstrates how sorted input creates a worst-case O(N) tree.

### C. Predecessor & Successor
7. **In-order Predecessor**: `7_bst_inorder_predecessor.c/cpp`
    - Finds largest node smaller than target.
8. **In-order Successor**: `8_bst_inorder_successor.c/cpp`
    - Finds smallest node larger than target.

### D. Height & Balancing
9. **Find Height**: `9_bst_height.c/cpp`
    - Explains O(N) height in skewed trees vs O(log N) in balanced trees.
10. **Compute Balance Factor**: `10_bst_balance_factor.c/cpp`
    - `Height(Left) - Height(Right)`. Introduction to AVL concepts.

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
