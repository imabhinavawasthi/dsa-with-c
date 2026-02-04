// File: 21_traverse_cll.cpp
// Title: Traverse Circular Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traverse(Node* head) {
    if (head == NULL) {
        cout << "Empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Circular: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)" << endl;
}

int main() {
    Node* head = new Node();
    Node* two = new Node();
    
    head->data = 1; head->next = two;
    two->data = 2; two->next = head;

    traverse(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
