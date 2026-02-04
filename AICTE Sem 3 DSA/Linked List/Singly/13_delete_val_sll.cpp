// File: 13_delete_val_sll.cpp
// Title: Delete Node with Specific Value in Singly Linked List (C++)
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

void deleteByValue(Node* &head, int key) {
    if (head == NULL) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        cout << "Deleting: " << key << endl;
        delete temp;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Val " << key << " not found." << endl;
        return;
    }

    prev->next = temp->next;
    cout << "Deleting: " << key << endl;
    delete temp;
}

int main() {
    // 5 -> 15 -> 25
    Node* head = new Node(); head->data = 5;
    head->next = new Node(); head->next->data = 15;
    head->next->next = new Node(); head->next->next->data = 25;
    head->next->next->next = NULL;

    display(head);
    
    deleteByValue(head, 15);
    display(head);

    deleteByValue(head, 99); // Not found

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
