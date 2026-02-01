#include <stdio.h>

/*
 Demonstrates different SPACE COMPLEXITIES:
 O(1), O(n), and O(log n)
*/

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void binarySearchRec(int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;
        binarySearchRec(low, mid - 1);
    }
}

int main() {

    /* -------------------- O(1) Space -------------------- */

    // Example 1: Simple variables
    int a = 10, b = 20, sum;
    sum = a + b;
    printf("O(1) Space Example: %d\n", sum);

    // Example 2: Array access without extra memory
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Array element: %d\n", arr[2]);

    /* -------------------- O(n) Space -------------------- */

    // Example 3: Extra array of size n
    int n = 5;
    int arr2[5];

    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }

    printf("O(n) Space Example: Extra array created\n");

    // Example 4: Recursion with depth n (factorial)
    factorial(5);
    printf("O(n) Space Example: Recursive factorial\n");

    /* -------------------- O(log n) Space -------------------- */

    // Example 5: Recursive binary search (log n stack depth)
    binarySearchRec(0, 16);
    printf("O(log n) Space Example: Recursive binary search\n");

    return 0;
}
