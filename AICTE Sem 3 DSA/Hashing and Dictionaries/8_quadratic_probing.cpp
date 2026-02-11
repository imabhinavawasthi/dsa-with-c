/*
 * File: 8_quadratic_probing.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Hash Table using Quadratic Probing in C++.
 *
 * Probe Sequence: (hash(key) + i*i) % SIZE
 *
 * Note on Table Size:
 * For Quadratic Probing to work best, Table Size should be a Prime Number found to satisfy
 * the condition (4k+3). This guarantees coverage of half the table. 
 * Here we use a small prime for demonstration.
 *
 * Time Complexity: O(1) average.
 */

#include <iostream>
using namespace std;

#define SIZE 7

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
        int h = hashFunction(key);

        // Check for duplicate update
        for (int i = 0; i < SIZE; i++) {
            int index = (h + i * i) % SIZE;
            if (table[index].status == OCCUPIED && table[index].key == key) {
                cout << "Key " << key << " exists. Updating value." << endl;
                table[index].value = value;
                return;
            }
            if (table[index].status == EMPTY) break; 
        }

        // Insert
        for (int i = 0; i < SIZE; i++) {
            int index = (h + i * i) % SIZE;

            if (table[index].status != OCCUPIED) {
                table[index].key = key;
                table[index].value = value;
                table[index].status = OCCUPIED;
                cout << "Inserted (" << key << ", " << value << ") at Index " << index << " (i=" << i << ")" << endl;
                return;
            }
        }
        cout << "Table Full or Slot Not Found!" << endl;
    }

    int search(int key) {
        int h = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (h + i * i) % SIZE;

            if (table[index].status == EMPTY) return -1;

            if (table[index].status == OCCUPIED && table[index].key == key) {
                return table[index].value;
            }
        }
        return -1;
    }

    void deleteKey(int key) {
        int h = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (h + i * i) % SIZE;

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
        cout << "\n--- Quadratic Probing Hash Table (C++) ---" << endl;
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
