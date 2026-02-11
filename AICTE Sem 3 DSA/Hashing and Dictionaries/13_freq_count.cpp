/*
 * File: 13_freq_count.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program counts the frequency of elements using Hashing in C++.
 * NO STL used.
 *
 * We implement a custom Hash Map to store (Key -> Count).
 *
 * Time Complexity: O(n)
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

        // Search for existing key
        while (temp != NULL) {
            if (temp->key == key) {
                temp->count++;
                return;
            }
            temp = temp->next;
        }

        // Not found, insert new node
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() {
        cout << "Element  |  Frequency" << endl;
        cout << "---------------------" << endl;
        for (int i = 0; i < SIZE; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "   " << temp->key << "\t |     " << temp->count << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    int arr[] = {5, 10, 5, 20, 5, 10, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    FrequencyMap freqMap;

    cout << "Input Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl << endl;

    for (int i = 0; i < n; i++) {
        freqMap.insert(arr[i]);
    }

    freqMap.display();

    return 0;
}
