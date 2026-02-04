#include <stdio.h>

/*
 Demonstrates O(log n) Time Complexity
*/

int main() {

    int n = 32;

    // Example 1: Repeated division
    while(n > 1) {
        n = n / 2;
        printf("%d ", n);
    }
    printf("\n");

    for(int i = 1; i < n; i*=2) {
        printf("%d ", i);
    }
    // 1,2,4,8,... so runs log(n) times which is O(log n)

    // Example 2: Binary search idea (loop count)
    int low = 0, high = 16;
    while(low <= high) {
        int mid = (low + high) / 2;
        high = mid - 1;
    }

    // Example 3: Power of two reduction
    int x = 64;
    while(x > 0) {
        x = x >> 1;   // divide by 2
    }

    return 0;
}
