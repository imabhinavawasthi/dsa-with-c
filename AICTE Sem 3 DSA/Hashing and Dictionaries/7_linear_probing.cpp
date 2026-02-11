/*
 * File: 7_linear_probing.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table using Linear Probing in C++.
 *
 * Open Addressing Method:
 * All elements are stored in the hash table array itself.
 *
 * Key Concepts:
 * 1. Probe Sequence: i, i+1, i+2...
 * 2. Primary Clustering: Tendency for occupied slots to build up, increasing collision chance.
 * 3. Lazy Deletion: Deleting marks a slot as 'DELETED' allowing searches to pass over it.
 *
 * Time Complexity:
 * - Average: O(1)
 * - Worst: O(n)
 */

#include <iostream>
using namespace std;

#define SIZE 10

enum Status { EMPTY, OCCUPIED, DELETED };

struct HashSlot {
    int key;
    int value;
    Status status;

    HashSlot() {
        status = EMPTY;
    }
};

class HashTable {
private:
    HashSlot table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    void insert(int key, int value) {
        int index = hashFunction(key);
        int start = index;

        // Check update first
        int tempIndex = index;
        while (table[tempIndex].status != EMPTY) {
            if (table[tempIndex].status == OCCUPIED && table[tempIndex].key == key) {
                cout << "Key " << key << " exists at Index " << tempIndex << ". Updating value." << endl;
                table[tempIndex].value = value;
                return;
            }
            tempIndex = (tempIndex + 1) % SIZE;
            if (tempIndex == start) break;
        }

        // Find insertion spot (Occupied slots are skipped)
        while (table[index].status == OCCUPIED) {
            index = (index + 1) % SIZE;
            if (index == start) {
                cout << "Hash Table is FULL!" << endl;
                return;
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].status = OCCUPIED;
        cout << "Inserted (" << key << ", " << value << ") at Index " << index << endl;
    }

    int search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].status != EMPTY) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        return -1; // Not found
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].status != EMPTY) {
            if (table[index].status == OCCUPIED && table[index].key == key) {
                table[index].status = DELETED; // Lazy Deletion
                cout << "Key " << key << " deleted from Index " << index << "." << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        cout << "Key not found!" << endl;
    }

    void display() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (table[i].status == OCCUPIED) {
                cout << "Index " << i << ": [" << table[i].key << " : " << table[i].value << "]" << endl;
            } else if (table[i].status == DELETED) {
                cout << "Index " << i << ": [DELETED]" << endl;
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
        cout << "\n--- Linear Probing Hash Table (C++) ---" << endl;
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
// Space Complexity: O(m)
