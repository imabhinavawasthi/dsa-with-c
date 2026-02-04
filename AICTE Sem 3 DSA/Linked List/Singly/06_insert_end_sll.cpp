// File: 06_insert_end_sll.cpp
// Title: Insert Node at End of Singly Linked List (C++)
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

// Pass head by reference to handle empty list case easily
void insertAtEnd(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    cout << "Inserting 100 at end..." << endl;
    insertAtEnd(head, 100);
    display(head);

    cout << "Inserting 200 at end..." << endl;
    insertAtEnd(head, 200);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
