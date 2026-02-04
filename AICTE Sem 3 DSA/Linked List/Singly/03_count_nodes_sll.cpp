// File: 03_count_nodes_sll.cpp
// Title: Count Number of Nodes in a Singly Linked List (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    
    // List: 100 -> 200 -> NULL
    head->data = 100;
    head->next = second;
    
    second->data = 200;
    second->next = NULL;

    cout << "Total nodes: " << countNodes(head) << endl;

    delete head;
    delete second;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
