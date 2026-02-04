// File: 11_delete_end_sll.cpp
// Title: Delete Node from End of Singly Linked List (C++)
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

void deleteFromEnd(Node* &head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        cout << "Deleting: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    cout << "Deleting: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
}

int main() {
    // List: 5 -> 10 -> 15
    Node* head = new Node(); head->data = 5;
    head->next = new Node(); head->next->data = 10;
    head->next->next = new Node(); head->next->next->data = 15;
    head->next->next->next = NULL;

    cout << "Original: "; display(head);

    deleteFromEnd(head);
    display(head);

    deleteFromEnd(head);
    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
