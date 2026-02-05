// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node {
    int data;       // Data part
    Node* next;     // Pointer to next node
};

Node* getNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void printDetails(Node* head) {
    Node* curr = head;
    while(curr!=NULL) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<"\n";
}

int main() {
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    
    // values
    a->data = 10;
    b->data = 7;
    c->data = 20;
    
    // link the nodes
    a->next = b;
    b->next = c;
    c->next = NULL;
    
    Node* head = a;
    printDetails(head);

    // insert at the beginning
    Node* newNode = getNewNode(2);
    newNode->next = head;
    head = newNode;
    printDetails(head);
    
    // insert at the end
    newNode = getNewNode(4);
    Node* curr = head;
    while(curr->next!=NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    printDetails(head);
    
    // insert at position k
    int k = 3;
    newNode = getNewNode(5);
    curr = head;
    for(int i=0;i<k-1;i++) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    printDetails(head);
    
    // delete the first node
    head = head->next;
    printDetails(head);
    
    // delete the last node
    curr = head;
    while(curr->next->next!=NULL) {
        curr = curr->next;
    }
    curr->next = NULL;
    printDetails(head);
    
    // delete the kth node
    curr = head;
    for(int i=0;i<k-2;i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    printDetails(head);

    return 0;
}