/*
 * File: 1_dict_array.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Dictionary ADT using a static Array in C++.
 * NO STL (Standard Template Library) is used.
 *
 * Dictionary ADT:
 * A Dictionary stores Key-Value pairs.
 * Operations: Insert, Search, Delete.
 *
 * Time Complexity:
 * - Insert: O(n) (Due to duplicate check)
 * - Search: O(n)
 * - Delete: O(n)
 *
 * Space Complexity: O(n)
 */

#include <iostream>
using namespace std;

#define MAX 100

class Dictionary {
private:
    struct Element {
        int key;
        int value;
    };

    Element items[MAX];
    int size;

public:
    Dictionary() {
        size = 0;
    }

    void insert(int key, int value) {
        if (size == MAX) {
            cout << "Dictionary is FULL!" << endl;
            return;
        }

        // Check for duplicate
        for (int i = 0; i < size; i++) {
            if (items[i].key == key) {
                cout << "Key " << key << " exists. Updating value." << endl;
                items[i].value = value;
                return;
            }
        }

        items[size].key = key;
        items[size].value = value;
        size++;
        cout << "Inserted (" << key << ", " << value << ")" << endl;
    }

    int search(int key) {
        for (int i = 0; i < size; i++) {
            if (items[i].key == key) {
                return items[i].value;
            }
        }
        return -1; // Assuming -1 means not found
    }

    void deleteKey(int key) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (items[i].key == key) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Key not found!" << endl;
            return;
        }

        // Shift elements
        for (int i = index; i < size - 1; i++) {
            items[i] = items[i + 1];
        }
        size--;
        cout << "Key " << key << " deleted." << endl;
    }

    void display() {
        if (size == 0) {
            cout << "Dictionary is empty." << endl;
            return;
        }
        cout << "Dictionary Contents: ";
        for (int i = 0; i < size; i++) {
            cout << "[" << items[i].key << " : " << items[i].value << "] ";
        }
        cout << endl;
    }
};

int main() {
    Dictionary myDict;
    int choice, key, value;

    while (true) {
        cout << "\n--- Dictionary ADT (Array - C++) ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                myDict.insert(key, value);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                value = myDict.search(key);
                if (value != -1) cout << "Found value: " << value << endl;
                else cout << "Key not found." << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                myDict.deleteKey(key);
                break;
            case 4:
                myDict.display();
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
// Insert: O(n)
// Search: O(n)
// Delete: O(n)
// Space Complexity: O(n)
