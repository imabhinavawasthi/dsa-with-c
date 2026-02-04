// File: 07_insert_pos_sll.cpp
// Title: Insert Node at Specific Position in Singly Linked List (C++)
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

void insertAtPosition(Node* &head, int newData, int position) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position " << position << " is out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = NULL;
    
    insertAtPosition(head, 100, 1);
    insertAtPosition(head, 200, 2); 
    
    cout << "Initial List: ";
    display(head);

    cout << "Inserting 150 at position 2..." << endl;
    insertAtPosition(head, 150, 2);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
