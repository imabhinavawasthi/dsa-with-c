// File: 22_insert_cll.cpp
// Title: Insert Node in Circular Linked List (C++)
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

void insertAtBegin(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
    head = newNode; // Make new node head
}

int main() {
    Node* head = NULL;
    
    insertAtBegin(head, 20);
    display(head);

    insertAtBegin(head, 10);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
