/*
 * File: 5_hash_functions.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates different Hash Functions for Integers and Strings.
 *
 * 1. Integer Hashing: Modulo Arithmetic (k % m).
 * 2. String Hashing:
 *    a) Sum of ASCII Values (Simple, but has collisions for permutations like "ABC" and "CBA").
 *    b) Polynomial Rolling Hash (Better distribution using a prime multiplier).
 *
 * Goal: To show how keys are mapped to indices [0 to m-1].
 */

#include <stdio.h>
#include <string.h>

// Function Prototypes
int hashInt(int key, int m);
int hashStringSum(char *key, int m);
int hashStringPoly(char *key, int m);

int main() {
    int m, choice, intKey;
    char strKey[100];

    printf("Enter Hash Table Size (m): ");
    scanf("%d", &m);

    while (1) {
        printf("\n--- Hash Function Design ---\n");
        printf("1. Hash Integer (Modulo)\n");
        printf("2. Hash String (ASCII Sum)\n");
        printf("3. Hash String (Polynomial Rolling Hash)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Integer Key: ");
                scanf("%d", &intKey);
                printf("Hash Value: %d\n", hashInt(intKey, m));
                break;
            case 2:
                printf("Enter String Key: ");
                scanf("%s", strKey);
                printf("Hash Value (ASCII Sum): %d\n", hashStringSum(strKey, m));
                break;
            case 3:
                printf("Enter String Key: ");
                scanf("%s", strKey);
                printf("Hash Value (Polynomial): %d\n", hashStringPoly(strKey, m));
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// 1. Integer Hash Function
// Uses simple modulo operator.
int hashInt(int key, int m) {
    return key % m;
}

// 2. String Hash - ASCII Sum
// Sums up ASCII values of all characters.
// Problem: Permutations ("ABC", "CBA", "BCA") have SAME hash.
int hashStringSum(char *key, int m) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % m;
}

// 3. String Hash - Polynomial
// Uses a prime multiplier (like 31) to weigh positions.
// hash = (s[0]*p^0 + s[1]*p^1 + ...) % m
// Reduced using Horner's Rule: hash = (hash * p + char) % m
int hashStringPoly(char *key, int m) {
    long long hash = 0;
    const int p = 31; // Prime multiplier
    
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * p + key[i]) % m;
    }
    // Ensure positive result
    return (int)(hash < 0 ? hash + m : hash);
}

// Time Complexity:
// Integer Hash: O(1)
// String Hash: O(L) where L is string length.
