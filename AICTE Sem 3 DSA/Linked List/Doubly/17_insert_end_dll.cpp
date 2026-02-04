// File: 17_insert_end_dll.cpp
// Title: Insert at End of Doubly Linked List (C++)
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

void insertAtEnd(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node* head = NULL;

    cout << "Insert 100 at end..." << endl;
    insertAtEnd(head, 100);
    display(head);

    cout << "Insert 200 at end..." << endl;
    insertAtEnd(head, 200);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
