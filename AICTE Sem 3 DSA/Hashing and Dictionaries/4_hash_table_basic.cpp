/*
 * File: 4_hash_table_basic.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Basic Hash Table in C++.
 * Uses simple Divison Method Hash Function: h(k) = k % size
 *
 * NOTE:
 * This is a foundational example. It DOES NOT handle collisions.
 * Collisions result in data loss (overwrite).
 *
 * Time Complexity: Excellent O(1) for all operations (assuming no collisions/direct map).
 */

#include <iostream>
using namespace std;

#define SIZE 10

struct HashSlot {
    int key;
    int value;
    bool is_occupied;

    HashSlot() {
        is_occupied = false;
    }
};

class HashTable {
private:
    HashSlot table[SIZE];

    int hashFunction(int key) {
        return key % SIZE; // Simple Modulus
    }

public:
    void insert(int key, int value) {
        int index = hashFunction(key);

        if (table[index].is_occupied) {
            cout << "WARNING: Collision at index " << index << "! Overwriting Key " << table[index].key << endl;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].is_occupied = true;
        cout << "Inserted (" << key << ", " << value << ") at Index " << index << endl;
    }

    int search(int key) {
        int index = hashFunction(key);

        if (table[index].is_occupied && table[index].key == key) {
            return table[index].value;
        }
        return -1; // Not found
    }

    void deleteKey(int key) {
        int index = hashFunction(key);

        if (table[index].is_occupied && table[index].key == key) {
            table[index].is_occupied = false;
            cout << "Key " << key << " deleted from Index " << index << "." << endl;
        } else {
            cout << "Key not found!" << endl;
        }
    }

    void display() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (table[i].is_occupied) {
                cout << "Index " << i << ": [" << table[i].key << " : " << table[i].value << "]" << endl;
            } else {
                cout << "Index " << i << ": ---" << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice, key, value;

    while (true) {
        cout << "\n--- Basic Hash Table (C++) ---" << endl;
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

// Time Complexity (Average & Worst Case):
// Insert: O(1)
// Search: O(1)
// Delete: O(1)
// Space Complexity: O(m)
