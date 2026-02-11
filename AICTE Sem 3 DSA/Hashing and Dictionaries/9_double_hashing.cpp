/*
 * File: 9_double_hashing.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table using Double Hashing in C++.
 *
 * Double Hashing eliminates clustering by making the probe step dependent on the key.
 * 
 * Formula: index = (h1(key) + i * h2(key)) % SIZE
 */

#include <iostream>
using namespace std;

#define SIZE 11
#define PRIME 7

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

    int hash1(int key) {
        return key % SIZE;
    }

    int hash2(int key) {
        return PRIME - (key % PRIME);
    }

public:
    void insert(int key, int value) {
        int h1 = hash1(key);
        int h2 = hash2(key);

        // Check update
        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;
            if (table[index].status == OCCUPIED && table[index].key == key) {
                cout << "Key " << key << " exists. Updating value." << endl;
                table[index].value = value;
                return;
            }
            if (table[index].status == EMPTY) break;
        }

        // Insert
        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (table[index].status != OCCUPIED) {
                table[index].key = key;
                table[index].value = value;
                table[index].status = OCCUPIED;
                cout << "Inserted (" << key << ", " << value << ") at Index " << index << " (i=" << i << ")" << endl;
                return;
            }
        }
        cout << "Table Full!" << endl;
    }

    int search(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (table[index].status == EMPTY) return -1;

            if (table[index].status == OCCUPIED && table[index].key == key) {
                return table[index].value;
            }
        }
        return -1;
    }

    void deleteKey(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (table[index].status == EMPTY) {
                cout << "Key not found!" << endl;
                return;
            }

            if (table[index].status == OCCUPIED && table[index].key == key) {
                table[index].status = DELETED;
                cout << "Key " << key << " deleted from Index " << index << "." << endl;
                return;
            }
        }
        cout << "Key not found!" << endl;
    }

    void display() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (table[i].status == OCCUPIED) {
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
        cout << "\n--- Double Hashing Hash Table (C++) ---" << endl;
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
