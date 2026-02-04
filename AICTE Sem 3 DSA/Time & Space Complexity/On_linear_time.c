#include <stdio.h>

/*
 Demonstrates O(n) Time Complexity
*/

int main() {

    int n = 5;

    // Example 1: Printing numbers
    for(int i = 0; i < n; i+=2) {
        printf("%d ", i);
    }
    // i=0,2,4,6,... so runs n/2 times which is O(n)
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
    for(int i = 0; i < 2*n + 1000000; i++) { // 2*n + 1000000 is still O(n)
        sum += arr[i];
        for (int j = 0; j < 1000; j++) { // Inner loop with constant iterations
            sum += 1;
        }
    }
    printf("Sum = %d\n", sum);

    return 0;
}
