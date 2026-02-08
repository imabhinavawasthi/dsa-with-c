# Heaps and Priority Queue Programs (C and C++)

This directory contains exam-oriented implementations of Heaps (Min/Max) and Priority Queues using Array Representation.

Each program is provided in both **C (.c)** and **C++ (.cpp)** versions.
The code uses strict array-based logic without STL, handling index calculations manually:
- `Parent = (i - 1) / 2`
- `Left = 2*i + 1`
- `Right = 2*i + 2`

## List of Programs

### A. Priority Queue Basics
1. **Min Priority Queue**: `1_min_priority_queue.c/cpp`
   - Complete implementation (Insert & ExtractMin).
2. **Max Priority Queue**: `2_max_priority_queue.c/cpp`
   - Complete implementation (Insert & ExtractMax).
3. **Find Min Operation**: `3_find_min.c/cpp`
   - Demonstrates O(1) peek.

### B. Heap Operations (Step-by-Step)
4. **Array Representation**: `4_min_heap_array.c/cpp`
   - Displays array elements with their Parent/Child relationships.
5. **Insert & Heapify Up**: `5_min_heap_insert.c/cpp`
   - Focuses on the "Bubble Up" logic.
6. **Delete Min & Heapify Down**: `6_min_heap_delete.c/cpp`
   - Focuses on the "Sink Down" logic.
7. **Modify Key**: `7_min_heap_modify.c/cpp`
   - Decrease and Increase Key operations.
8. **Build Heap**: `8_heapify_build.c/cpp`
   - O(N) algorithm to convert arbitrary array to heap.

### C. Advanced Applications
9. **Heap Sort**: `9_heap_sort.c/cpp`
   - O(N log N) in-place sorting algorithm.
10. **K-ary Heap**: `10_k_ary_heap_insert.c/cpp`
    - Generalization where nodes have K children.

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
