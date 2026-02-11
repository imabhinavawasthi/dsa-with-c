/*
 * File: 14_array_equality.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program checks if two arrays are equal using Hashing in C++.
 * NO STL used.
 *
 * Complexity: O(n)
 */

#include <iostream>
using namespace std;

#define SIZE 20

struct Node {
    int key;
    int count;
    Node* next;

    Node(int k) {
        key = k;
        count = 1;
        next = NULL;
    }
};

class FrequencyMap {
private:
    Node* table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    FrequencyMap() {
        for (int i = 0; i < SIZE; i++) table[i] = NULL;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) {
                temp->count++;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool decrement(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) {
                if (temp->count > 0) {
                    temp->count--;
                    return true;
                }
                return false;
            }
            temp = temp->next;
        }
        return false;
    }
    
    ~FrequencyMap() {
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

bool areArraysEqual(int arr1[], int n1, int arr2[], int n2) {
    if (n1 != n2) return false;

    FrequencyMap map;

    for (int i = 0; i < n1; i++) map.insert(arr1[i]);

    for (int i = 0; i < n2; i++) {
        if (!map.decrement(arr2[i])) return false;
    }

    return true;
}

int main() {
    int arr1[] = {1, 2, 5, 4, 0};
    int arr2[] = {2, 4, 5, 0, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Array 1: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    cout << "Array 2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    if (areArraysEqual(arr1, n1, arr2, n2)) {
        cout << "Result: Arrays are Equal" << endl;
    } else {
        cout << "Result: Arrays are NOT Equal" << endl;
    }

    return 0;
}
