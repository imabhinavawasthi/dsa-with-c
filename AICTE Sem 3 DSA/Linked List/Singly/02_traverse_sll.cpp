// File: 02_traverse_sll.cpp
// Title: Traverse a Singly Linked List (C++)
// Author: Abhinav Awasthi
// Description: This program creates a linked list and traverses it using C++.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to traverse and print the list
void traverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    cout << "Traversing List: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create nodes using new usually
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    traverse(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
