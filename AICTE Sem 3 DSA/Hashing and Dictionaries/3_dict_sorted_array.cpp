/*
 * File: 3_dict_sorted_array.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Dictionary ADT using a Sorted Array in C++.
 * NO STL is used.
 *
 * Key Feature: BINARY SEARCH for O(log n) search operations.
 *
 * Operations:
 * - Insert: O(n) (Keep array sorted)
 * - Search: O(log n)
 * - Delete: O(n)
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

    // Use Binary Search helper (private)
    int binarySearch(int key) {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (items[mid].key == key)
                return mid;
            else if (items[mid].key < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

public:
    Dictionary() {
        size = 0;
    }

    void insert(int key, int value) {
        if (size == MAX) {
            cout << "Dictionary is FULL!" << endl;
            return;
        }

        // Check duplicate
        int index = binarySearch(key);
        if (index != -1) {
            cout << "Key " << key << " exists. Updating value." << endl;
            items[index].value = value;
            return;
        }

        // Insert in sorted order
        int i = size - 1;
        while (i >= 0 && items[i].key > key) {
            items[i + 1] = items[i]; // Shift right
            i--;
        }

        items[i + 1].key = key;
        items[i + 1].value = value;
        size++;
        cout << "Inserted (" << key << ", " << value << ")" << endl;
    }

    int search(int key) {
        int index = binarySearch(key);
        if (index != -1) return items[index].value;
        return -1; // Not found
    }

    void deleteKey(int key) {
        int index = binarySearch(key);
        if (index == -1) {
            cout << "Key not found!" << endl;
            return;
        }

        // Shift left
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
        cout << "Dictionary Contents (Sorted): ";
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
        cout << "\n--- Dictionary ADT (Sorted Array - C++) ---" << endl;
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

// Time Complexity:
// Insert: O(n)
// Search: O(log n)
// Delete: O(n)
