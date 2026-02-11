/*
 * File: 6_separate_chaining.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table with Separate Chaining in C++.
 * NO STL used. Manual management of linked lists.
 *
 * Collision Resolution:
 * Uses Linked Lists (Chains) to store multiple elements at the same bucket.
 *
 * Time Complexity:
 * - Average: O(1)
 * - Worst: O(n) (All keys collide)
 */

#include <iostream>
using namespace std;

#define SIZE 7

// Node structure
struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
private:
    Node* table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    ~HashTable() {
        // Free all memory
        for (int i = 0; i < SIZE; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        // Check for duplicates
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) {
                cout << "Key " << key << " exists at Index " << index << ". Updating value." << endl;
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        // Insert at Head
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Inserted (" << key << ", " << value << ") at Index " << index << endl;
    }

    int search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1; // Not found
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        Node *temp = table[index], *prev = NULL;

        if (temp == NULL) {
            cout << "Key not found!" << endl;
            return;
        }

        if (temp->key == key) {
            table[index] = temp->next;
            delete temp;
            cout << "Key " << key << " deleted from Index " << index << "." << endl;
            return;
        }

        while (temp != NULL && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Key not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Key " << key << " deleted from Index " << index << "." << endl;
    }

    void display() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            if (temp == NULL) {
                cout << "NULL";
            } else {
                while (temp != NULL) {
                    cout << "[" << temp->key << " : " << temp->value << "] -> ";
                    temp = temp->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key, value;

    while (true) {
        cout << "\n--- Separate Chaining Hash Table (C++) ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display Table" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                ht.insert(key, value);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                value = ht.search(key);
                if (value != -1) cout << "Found value: " << value << endl;
                else cout << "Key not found." << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.deleteKey(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

// Time Complexity: O(1) average.
// Space Complexity: O(m + n)
