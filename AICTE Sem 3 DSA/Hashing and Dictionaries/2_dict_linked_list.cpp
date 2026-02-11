/*
 * File: 2_dict_linked_list.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Dictionary ADT using a Singly Linked List in C++.
 * NO STL is used. Manual logical implementation of Linked List.
 *
 * Dictionary ADT:
 * Stores unique keys with associated values.
 *
 * Time Complexity:
 * - Insert: O(n) (Check duplicate)
 * - Search: O(n)
 * - Delete: O(n)
 *
 * Space Complexity: O(n)
 */

#include <iostream>
using namespace std;

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

class Dictionary {
private:
    Node* head;

public:
    Dictionary() {
        head = NULL;
    }

    // Destructor to free memory
    ~Dictionary() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int key, int value) {
        Node* temp = head;
        // Check for duplicates
        while (temp != NULL) {
            if (temp->key == key) {
                cout << "Key " << key << " exists. Updating value." << endl;
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        // Insert new node at head
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted (" << key << ", " << value << ")" << endl;
    }

    int search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1; // Not found
    }

    void deleteKey(int key) {
        Node *temp = head, *prev = NULL;

        // Validating list is not empty
        if (temp == NULL) {
            cout << "Dictionary is empty." << endl;
            return;
        }

        // If head node holds the key
        if (temp != NULL && temp->key == key) {
            head = temp->next;
            delete temp;
            cout << "Key " << key << " deleted." << endl;
            return;
        }

        // Search for key
        while (temp != NULL && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key not found
        if (temp == NULL) {
            cout << "Key not found!" << endl;
            return;
        }

        // Unlink and delete
        prev->next = temp->next;
        delete temp;
        cout << "Key " << key << " deleted." << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "Dictionary is empty." << endl;
            return;
        }
        cout << "Dictionary Contents:" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << "[" << temp->key << " : " << temp->value << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Dictionary myDict;
    int choice, key, value;

    while (true) {
        cout << "\n--- Dictionary ADT (Linked List - C++) ---" << endl;
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
