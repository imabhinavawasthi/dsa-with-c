// File: 19_traverse_dll.cpp
// Title: Traverse Doubly Linked List Forward and Backward (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void traverseForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void traverseBackward(Node* head) {
    if (head == NULL) return;
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(); head->data = 1;
    Node* mid = new Node(); mid->data = 2;
    Node* last = new Node(); last->data = 3;

    head->prev = NULL; head->next = mid;
    mid->prev = head; mid->next = last;
    last->prev = mid; last->next = NULL;

    traverseForward(head);
    traverseBackward(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
