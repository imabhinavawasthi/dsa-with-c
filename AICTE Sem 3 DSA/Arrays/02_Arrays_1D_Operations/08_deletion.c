/*
 * Program: 8. Delete an element from a given position
 * Language: C
 * Description: Deletes an element from an array by shifting subsequent elements to the left.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; // Current number of elements
    int pos, i;

    // 1. Display original array
    printf("Original Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2. Get input from user
    printf("\nEnter position to delete (index 0 to %d): ", n - 1);
    scanf("%d", &pos);

    // 3. Validation
    if(pos < 0 || pos >= n) {
        printf("Invalid position! Please enter position between 0 and %d\n", n - 1);
    } 
    else {
        // 4. Shift elements to the left to fill the gap
        // Start from the position to be deleted
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // 5. Decrease the count of elements
        n--; 

        // 6. Display updated array
        printf("\nArray after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(N) in worst case (deleting from index 0 requires shifting all elements).
// Space Complexity: O(1) auxiliary space.
