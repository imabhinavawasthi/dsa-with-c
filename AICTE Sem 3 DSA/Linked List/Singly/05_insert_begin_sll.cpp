// File: 05_insert_begin_sll.cpp
// Title: Insert Node at Beginning of Singly Linked List (C++)
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

// Function to insert at beginning
// We pass head by reference (Node* &head) so we can modify the original head pointer directly
void insertAtBeginning(Node* &head, int newData) {
    // 1. Create new node
    Node* newNode = new Node();
    
    // 2. Assign data
    newNode->data = newData;
    
    // 3. Link new node to current head
    newNode->next = head;
    
    // 4. Update head to point to new node
    head = newNode;
}

int main() {
    Node* head = NULL; // Empty list

    cout << "Inserting 5 at beginning..." << endl;
    insertAtBeginning(head, 5);
    display(head);

    cout << "Inserting 15 at beginning..." << endl;
    insertAtBeginning(head, 15);
    display(head);
    
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
