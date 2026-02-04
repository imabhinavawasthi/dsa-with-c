// File: 18_delete_node_dll.cpp
// Title: Delete Node from Doubly Linked List (C++)
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

void deleteNode(Node* &head, int key) {
    if (head == NULL) return;

    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Val " << key << " not found." << endl;
        return;
    }

    if (temp == head) {
        head = head->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    cout << "Deleting " << key << endl;
    delete temp;
}

int main() {
    // 5 <-> 15 <-> 25
    Node* head = new Node(); head->data = 5;
    head->next = new Node(); head->next->data = 15; head->prev = NULL;
    head->next->prev = head;
    head->next->next = new Node(); head->next->next->data = 25;
    head->next->next->prev = head->next; head->next->next->next = NULL;

    display(head);

    deleteNode(head, 15);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
