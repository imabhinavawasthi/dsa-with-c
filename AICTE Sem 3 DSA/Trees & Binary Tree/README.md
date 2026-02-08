# Tree and Binary Tree Programs (C and C++)

This directory contains simple, exam-oriented implementations of Tree Data Structures and Algorithms.

Each program is provided in both **C (.c)** and **C++ (.cpp)** versions.
The C++ versions use Classes and `new`/`delete` but **avoid STL** for exam compatibility.

## List of Programs

### A. Basic Tree Implementation & Traversals
1. **Manual Tree Creation**: `1_manual_tree_creation.c/cpp`
2. **Linked Representation**: `2_binary_tree_linked.c/cpp`
3. **In-order Traversal**: `3_inorder_traversal.c/cpp`
4. **Pre-order Traversal**: `4_preorder_traversal.c/cpp`
5. **Post-order Traversal**: `5_postorder_traversal.c/cpp`
6. **Height of Binary Tree**: `6_height_binary_tree.c/cpp`

### B. Tree Applications
7. **Count Total Nodes**: `7_count_nodes.c/cpp`
8. **Count Leaf Nodes**: `8_count_leaf_nodes.c/cpp`
9. **Search Element**: `9_search_binary_tree.c/cpp`

### C. Tree Construction from Traversals
10. **Build from Pre-order & In-order**: `10_build_tree_pre_in.c/cpp`
11. **Build from Post-order & In-order**: `11_build_tree_post_in.c/cpp`

### D. Advanced Applications
12. **Expression Tree Construction**: `12_expression_tree.c/cpp`  
    - Converts Postfix expression `ab-cd*e+/` to a tree.
    - Demonstrates In-order traversal to recover Infix form.

## How to Compile & Run
To run any C program:
```bash
gcc filename.c -o output
./output
```

To run any C++ program:
```bash
g++ filename.cpp -o output
./output
```
