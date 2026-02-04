// File: 14_delete_step_sll.cpp
// Title: Step-by-Step Deletion Explanation (Dry Run Helper) (C++)
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
    cout << "List Content: ";
    while (temp != NULL) {
        cout << "[" << temp->data << "|*] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- DRY RUN: DELETE FROM BEGINNING ---" << endl << endl;

    // Create a list: 50 -> 60 -> NULL
    Node* head = new Node(); head->data = 50;
    head->next = new Node(); head->next->data = 60;
    head->next->next = NULL;

    cout << "Step 0: Initial State" << endl;
    display(head);
    cout << endl;

    cout << "Step 1: Check if list is empty." << endl;
    cout << "Result: Not empty." << endl;

    cout << "Step 2: Store head in temp." << endl;
    Node* temp = head;
    cout << "temp -> [" << temp->data << "]" << endl;

    cout << "Step 3: Update head = head->next." << endl;
    head = head->next;
    cout << "Head is now pointing to [" << head->data << "]" << endl;

    cout << "Step 4: Delete temp." << endl;
    delete temp;
    cout << "Node deleted." << endl;

    cout << "Step 5: Final State" << endl;
    display(head);

    return 0;
}

// Time Complexity: O(1) per step
// Space Complexity: O(1)
