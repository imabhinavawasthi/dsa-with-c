#include <stdio.h>

/*
 Demonstrates O(n) Time Complexity
*/

int main() {

    int n = 5;

    // Example 1: Printing numbers
    for(int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Example 2: Linear search (worst case)
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 60;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Found\n");
        }
    }

    // Example 3: Sum of array elements
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum = %d\n", sum);

    return 0;
}
