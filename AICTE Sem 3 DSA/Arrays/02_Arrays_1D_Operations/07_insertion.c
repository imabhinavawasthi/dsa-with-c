/*
 * Program: 7. Insert an element at a given position
 * Language: C
 * Description: Inserts a new element into an array at a specific index by shifting elements.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; // Current number of elements
    int pos, value, i;

    // 1. Display original array
    printf("Original Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2. Get input from user
    printf("\nEnter position to insert (index 0 to %d): ", n);
    scanf("%d", &pos);
    
    printf("Enter value to insert: ");
    scanf("%d", &value);

    // 3. Validation
    if(pos < 0 || pos > n) {
        printf("Invalid position! Please enter position between 0 and %d\n", n);
    } 
    else {
        // 4. Shift elements to the right to make space
        // Start from the last element and move backwards
        for(i = n - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }

        // 5. Insert the new value at the correct position
        arr[pos] = value;
        n++; // Increase the count of elements

        // 6. Display updated array
        printf("\nArray after insertion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

// Time Complexity: O(N) in worst case (inserting at index 0 requires shifting all elements).
// Space Complexity: O(1) auxiliary space (using static array).
