// File: 09_insert_step_sll.cpp
// Title: Step-by-Step Insertion Explanation (Dry Run Helper) (C++)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    Node* temp = head;
    cout << "List Content: ";
    while (temp != NULL) {
        cout << "[" << temp->data << "|*] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- DRY RUN: INSERT AT BEGINNING ---" << endl << endl;

    Node* head = NULL;
    cout << "Step 0: Initial State" << endl;
    cout << "HEAD -> NULL" << endl << endl;

    cout << "Step 1: User wants to insert 10." << endl;
    cout << "Step 2: Allocate memory for new node (temp)." << endl;
    Node* temp = new Node();
    
    cout << "Step 3: Assign data 10 to temp->data." << endl;
    temp->data = 10;
    
    cout << "Step 4: Point temp->next to current HEAD (NULL)." << endl;
    temp->next = head;
    
    cout << "Step 5: Update HEAD to point to temp." << endl;
    head = temp;
    
    display(head);
    cout << endl;

    cout << "--- DRY RUN: INSERT 20 AT BEGINNING ---" << endl << endl;
    
    cout << "Step 1: Allocate memory for new node (newNode)." << endl;
    Node* newNode = new Node();
    
    cout << "Step 2: Assign data 20 to newNode->data." << endl;
    newNode->data = 20;

    cout << "Step 3: Point newNode->next to current HEAD (node with 10)." << endl;
    newNode->next = head;

    cout << "Step 4: Update HEAD to point to newNode." << endl;
    head = newNode;

    display(head);

    return 0;
}

// Time Complexity: O(1) per step
// Space Complexity: O(1)
