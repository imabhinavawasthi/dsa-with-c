// File: 23_delete_cll.cpp
// Title: Delete Node from Circular Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)" << endl;
}

void deleteNode(Node* &head, int key) {
    if (head == NULL) return;

    Node *curr = head, *prev = NULL;

    if (head->data == key) {
        while (curr->next != head) {
            curr = curr->next;
        }

        if (curr == head) {
            delete head;
            head = NULL;
            return;
        }

        curr->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    prev = head;
    curr = head->next;
    while (curr != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        cout << "Val " << key << " not found." << endl;
        return;
    }
    
    prev->next = curr->next;
    delete curr;
}

int main() {
    Node* head = new Node(); Node* two = new Node(); Node* three = new Node();
    head->data = 100; head->next = two;
    two->data = 200; two->next = three;
    three->data = 300; three->next = head;

    display(head);

    deleteNode(head, 100);
    display(head);

    deleteNode(head, 300);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
