// File: 08_insert_after_val_sll.cpp
// Title: Insert Node After a Given Value in Singly Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAfterValue(Node* head, int targetVal, int newData) {
    Node* temp = head;
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << targetVal << " not found." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    // Create list: 5 -> 10 -> 15
    Node* head = new Node(); head->data = 5;
    head->next = new Node(); head->next->data = 10;
    head->next->next = new Node(); head->next->next->data = 15;
    head->next->next->next = NULL;

    cout << "Original: ";
    display(head);

    cout << "Inserting 12 after 10..." << endl;
    insertAfterValue(head, 10, 12);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
