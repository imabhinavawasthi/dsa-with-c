// File: 01_create_sll.cpp
// Title: Create and Display a Singly Linked List (C++)
// Author: Abhinav Awasthi
// Description: This program demonstrates how to create a simple singly linked list using classes/structs and new/delete in C++.
// NOTE: No STL (Standard Template Library) is used.

#include <iostream>
using namespace std;

// Define the Node class (or struct)
// struct is public by default, class is private by default
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to next node
};

// Function to print the linked list
void displayList(Node* head) {
    Node* temp = head; // Start from head
    
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next; // Move to next node
    }
    cout << "NULL" << endl;
}

int main() {
    // 1. Allocate memory for nodes using 'new'
    Node* first  = new Node();
    Node* second = new Node();
    Node* third  = new Node();

    // 2. Assign data and link nodes
    
    // First Node
    first->data = 10;
    first->next = second; // Link to second

    // Second Node
    second->data = 20;
    second->next = third; // Link to third

    // Third Node
    third->data = 30;
    third->next = NULL;   // Terminate list

    // Head points to the first node
    Node* head = first;

    // 3. Display the list
    displayList(head);

    // Free memory using 'delete'
    delete first;
    delete second;
    delete third;

    return 0;
}

// Time Complexity: O(n) for display
// Space Complexity: O(1) auxiliary space
