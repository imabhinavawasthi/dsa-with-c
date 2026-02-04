/*
 * Program: 9. Linear Search
 * Language: C
 * Description: Search for an element by checking each index sequentially.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[] = {10, 50, 30, 70, 80, 20};
    int n = 6;
    int target, i, found = 0;

    // 1. Input target from user
    printf("Array: 10, 50, 30, 70, 80, 20\n");
    printf("Enter element to search: ");
    scanf("%d", &target);

    // 2. Traverse array to find element
    for(i = 0; i < n; i++) {
        if(arr[i] == target) {
            printf("Element %d found at index %d\n", target, i);
            found = 1;
            break; // Stop searching once found
        }
    }

    // 3. If element not found
    if(found == 0) {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

// Time Complexity: O(N) - Worst case we check all elements.
// Space Complexity: O(1).
