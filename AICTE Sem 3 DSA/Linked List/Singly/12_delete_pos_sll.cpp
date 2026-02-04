// File: 12_delete_pos_sll.cpp
// Title: Delete Node at Specific Position in Singly Linked List (C++)
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

void deleteAtPosition(Node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    // Delete head
    if (position == 1) {
        head = head->next;
        cout << "Deleting: " << temp->data << endl;
        delete temp;
        return;
    }

    // Traverse to position - 1
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* toDelete = temp->next;
    cout << "Deleting: " << toDelete->data << endl;
    
    // Unlink
    temp->next = toDelete->next;
    
    // Free
    delete toDelete;
}

int main() {
    // List: 100 -> 200 -> 300
    Node* head = new Node(); head->data = 100;
    head->next = new Node(); head->next->data = 200;
    head->next->next = new Node(); head->next->next->data = 300;
    head->next->next->next = NULL;

    cout << "Original: "; display(head);

    cout << "Deleting pos 2..." << endl;
    deleteAtPosition(head, 2);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
