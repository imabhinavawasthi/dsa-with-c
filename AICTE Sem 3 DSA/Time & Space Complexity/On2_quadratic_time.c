#include <stdio.h>

/*
 Demonstrates O(n^2) Time Complexity
*/

int main() {

    int n = 4;

    // Example 1: Nested loops
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Example 2: Pair comparison
    int arr[4] = {1, 2, 3, 4};
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }

    // Example 3: Bubble sort logic
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return 0;
}
