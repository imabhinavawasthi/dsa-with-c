#include <stdio.h>

/*
 Demonstrates O(1) Time Complexity
*/

int main() {

    // Example 1: Variable assignment
    int x = 10;
    printf("Value of x: %d\n", x);

    // Example 2: Arithmetic operation
    int a = 5, b = 7;
    int sum = a + b;
    printf("Sum: %d\n", sum);

    // Example 3: Array access
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Array element: %d\n", arr[2]);

    return 0;
}
