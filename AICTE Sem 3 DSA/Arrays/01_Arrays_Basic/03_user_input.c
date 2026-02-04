/*
 * Program: 3. Input array elements from user
 * Language: C
 * Description: Takes input from the user to fill an array and then prints it.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    int n, i;
    int arr[100]; // Declare a large enough array (Static allocation)

    // 1. Ask user for the number of elements
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    // Validate input (Optional but good practice)
    if (n > 100 || n <= 0) {
        printf("Invalid size! Please enter a number between 1 and 100.\n");
        return 1;
    }

    // 2. Input elements using a loop
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // 3. Print the elements to verify
    printf("\nThe elements you entered are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Time Complexity: O(N) because we iterate through the loop N times for input and print.
// Space Complexity: O(100) -> O(1) constant space allocated, or O(N) used.
