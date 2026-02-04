// File: 04_search_sll.cpp
// Title: Search an Element in a Singly Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool search(Node* head, int key) {
    Node* current = head;
    int pos = 1;

    while (current != NULL) {
        if (current->data == key) {
            cout << "Element " << key << " found at position " << pos << "." << endl;
            return true;
        }
        current = current->next;
        pos++;
    }
    cout << "Element " << key << " not found." << endl;
    return false;
}

int main() {
    Node* head = new Node(); 
    Node* node2 = new Node();
    
    head->data = 55;
    head->next = node2;
    
    node2->data = 99;
    node2->next = NULL;

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    search(head, val);

    delete head;
    delete node2;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
