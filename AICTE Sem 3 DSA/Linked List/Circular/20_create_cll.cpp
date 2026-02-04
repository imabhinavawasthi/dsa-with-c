// File: 20_create_cll.cpp
// Title: Create and Display Circular Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) {
        cout << "Empty List" << endl;
        return;
    }
    Node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)" << endl;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    
    head->data = 5;
    head->next = second;
    
    second->data = 10;
    second->next = head; // Circular link

    display(head);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
