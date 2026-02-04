// File: 10_delete_begin_sll.cpp
// Title: Delete Node from Beginning of Singly Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteFromBeginning(Node* &head) {
    if (head == NULL) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    
    cout << "Deleting node with data: " << temp->data << endl;
    delete temp;
}

int main() {
    // List: 100 -> 200
    Node* head = new Node(); head->data = 100;
    head->next = new Node(); head->next->data = 200;
    head->next->next = NULL;

    cout << "Original List: ";
    display(head);

    deleteFromBeginning(head);
    display(head);

    deleteFromBeginning(head);
    display(head);

    deleteFromBeginning(head);

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
