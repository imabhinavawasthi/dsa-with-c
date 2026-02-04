// File: 15_create_dll.cpp
// Title: Create and Display Doubly Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void display(Node* head) {
    Node* temp = head;
    cout << "DLL: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();

    head->data = 100;
    head->prev = NULL;
    head->next = second;

    second->data = 200;
    second->prev = head;
    second->next = NULL;

    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
