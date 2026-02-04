// File: 16_insert_begin_dll.cpp
// Title: Insert at Beginning of Doubly Linked List (C++)
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
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

int main() {
    Node* head = NULL;

    cout << "Insert 20..." << endl;
    insertAtBeginning(head, 20);
    display(head);

    cout << "Insert 10..." << endl;
    insertAtBeginning(head, 10);
    display(head);

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
