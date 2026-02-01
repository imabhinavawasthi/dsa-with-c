#include <stdio.h>

/*
 Demonstrates O(n log n) Time Complexity
*/

int main() {

    int n = 8;

    // Example 1: Nested loop with division
    for(int i = 0; i < n; i++) {
        int x = n;
        while(x > 1) {
            x = x / 2;
            printf("%d ", x);
        }
        printf("\n");
    }

    // Example 2: Merge sort concept (iteration + divide)
    for(int i = 0; i < n; i++) {
        int size = n;
        while(size > 1) {
            size = size / 2;
        }
    }

    // Example 3: Log operation inside linear loop
    for(int i = 1; i <= n; i++) {
        int y = i;
        while(y > 1) {
            y = y / 2;
        }
    }

    return 0;
}
