/*
 * Program: 15. Static array vs dynamic array
 * Language: C
 * Description: Shows difference between stack-allocated (static) and heap-allocated (dynamic) arrays.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    // 1. Static Array (Allocated on Stack)
    // Size must be known at compile time (mostly)
    int staticArr[5] = {1, 2, 3, 4, 5};
    
    printf("Static Array (Stack): %d %d\n", staticArr[0], staticArr[1]);

    // 2. Dynamic Array (Allocated on Heap)
    // Size can be decided at runtime
    int n, i;
    int *dynamicArr;

    printf("\nEnter size for dynamic array: ");
    scanf("%d", &n);

    // malloc allocates memory and returns a pointer
    // (int*) is typecasting the void pointer to int pointer
    dynamicArr = (int*) malloc(n * sizeof(int));

    if (dynamicArr == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    // Input elements
    printf("Enter elements for dynamic array:\n");
    for(i = 0; i < n; i++) {
        dynamicArr[i] = (i + 1) * 10; // Auto-filling examples
    }

    // Printing
    printf("Dynamic Array (Heap): ");
    for(i = 0; i < n; i++) {
        printf("%d ", dynamicArr[i]);
    }
    printf("\n");

    // IMPORTANT: Always free dynamically allocated memory!
    free(dynamicArr);
    printf("Memory freed successfully.\n");

    return 0;
}

// Time Complexity: O(N) for allocation/access.
// Space Complexity: O(N) on Heap.
