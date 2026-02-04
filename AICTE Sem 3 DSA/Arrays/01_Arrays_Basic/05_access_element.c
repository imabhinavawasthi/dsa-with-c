/*
 * Program: 5. Demonstrate O(1) array access
 * Language: C
 * Description: Shows that accessing any element by index is instant (Constant Time).
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[] = {100, 200, 300, 400, 500};

    // Arrays are stored in contiguous memory.
    // Address of arr[i] = Base Address + (i * size_of_element)
    // This calculation happens instantly, O(1).

    printf("Array: {100, 200, 300, 400, 500}\n");

    // Random access examples
    printf("Accessing index 0: %d\n", arr[0]);
    printf("Accessing index 3: %d\n", arr[3]);
    printf("Accessing index 4: %d\n", arr[4]);

    return 0;
}

// Time Complexity: O(1) - Access speed does not depend on array size.
// Space Complexity: O(1) - No extra space used.
