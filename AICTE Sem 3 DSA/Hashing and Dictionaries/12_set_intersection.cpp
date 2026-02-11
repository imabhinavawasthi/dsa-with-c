/*
 * File: 12_set_intersection.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds the Set Intersection of two arrays using Hashing in C++.
 * NO STL used.
 *
 * Algorithm:
 * 1. Store unique elements of longer array into Hash Set (Actually, typically smaller one is better for space, but either works).
 *    Let's store Array 1.
 * 2. Iterate Array 2, check if element exists in Hash Set.
 * 3. If yes -> Print and Remove from Hash Set (to insure uniqueness).
 *
 * Time Complexity: O(n + m)
 */

#include <iostream>
using namespace std;

#define SIZE 20

struct Node {
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = NULL;
    }
};

class HashSet {
private:
    Node* table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashSet() {
        for (int i = 0; i < SIZE; i++) table[i] = NULL;
    }

    void insert(int key) {
        int index = hashFunction(key);
        // Avoid duplicates in set
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) return;
            temp = temp->next;
        }

        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Returns true if found, and REMOVES it to prevent duplicate printing
    bool searchAndRemove(int key) {
        int index = hashFunction(key);
        Node *temp = table[index], *prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    ~HashSet() {
        for (int i = 0; i < SIZE; i++) {
            Node* temp = table[i];
            while (temp) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 2}; // Note duplicate 2 in source
    int arr2[] = {2, 3, 6, 7};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    HashSet set;

    cout << "Array 1: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    cout << "Array 2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    // Insert Array 1 into Hash Set
    for (int i = 0; i < n1; i++) {
        set.insert(arr1[i]);
    }

    cout << "Intersection: ";
    bool found = false;
    for (int i = 0; i < n2; i++) {
        if (set.searchAndRemove(arr2[i])) {
            cout << arr2[i] << " ";
            found = true;
        }
    }
    
    if (!found) cout << "None";
    cout << endl;

    return 0;
}
