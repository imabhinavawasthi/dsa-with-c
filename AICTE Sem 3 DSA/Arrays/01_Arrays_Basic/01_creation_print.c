/*
 * Program: 1. Create an array and print elements
 * Language: C
 * Description: Demonstrates how to declare an array, assign values manually, and print them.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <stdio.h>

int main() {
    // 1. Array Declaration
    // int is the data type
    // numbers is the array name
    // [5] is the size of the array
    int numbers[5];

    // 2. Initialization (Assigning values index by index)
    // Array indices start from 0
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // 3. Printing elements
    printf("Element at index 0: %d\n", numbers[0]);
    printf("Element at index 1: %d\n", numbers[1]);
    printf("Element at index 2: %d\n", numbers[2]);
    printf("Element at index 3: %d\n", numbers[3]);
    printf("Element at index 4: %d\n", numbers[4]);

    return 0;
}

// Time Complexity: O(1) for accessing and printing each element individually.
// Space Complexity: O(N) where N is the size of the array (5 * 4 bytes = 20 bytes).
