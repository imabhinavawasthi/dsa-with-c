/*
 * File: 11_find_duplicates.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program finds duplicate elements in an array using Hashing in C++.
 * NO STL used. We implement a simple Hash Set logic.
 *
 * Logic:
 * Iterate array -> Check Hash Table -> If found, print -> Else Insert.
 *
 * Time Complexity: O(n) average.
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

    bool contains(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }
    
    // Destructor to clean up memory (Good practice)
    ~HashSet() {
         for(int i=0; i<SIZE; i++) {
             Node* temp = table[i];
             while(temp) {
                 Node* toDelete = temp;
                 temp = temp->next;
                 delete toDelete;
             }
         }
    }
};

int main() {
    int arr[] = {12, 45, 12, 67, 89, 45, 23, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    HashSet visited;

    cout << "Input Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Duplicates: ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        // Here we handle the specific case of "Printing duplicates only once"
        // But for simple "Find duplicates", printing every time we see a repeat is acceptable.
        // To print unique duplicates strictly, we'd need a second hash set "printed".
        // For simplicity, we just print if it's already in visited.
        
        // Wait, standard logic:
        // If seen before, it's a duplicate.
        // Note: This prints the duplicate EVERY time it appears again. E.g. {10, 10, 10} -> prints 10, 10.
        // This is usually acceptable for exams unless "unique duplicates" asked.
        
        if (visited.contains(arr[i])) {
            cout << arr[i] << " ";
            found = true;
        } else {
            visited.insert(arr[i]);
        }
    }
    
    if (!found) cout << "None";
    cout << endl;

    return 0;
}
