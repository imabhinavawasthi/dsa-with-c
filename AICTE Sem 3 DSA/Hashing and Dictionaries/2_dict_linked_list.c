/*
 * File: 2_dict_linked_list.c
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program implements a Dictionary ADT using a Singly Linked List.
 *
 * Why Linked List?
 * - Dynamic size (no fixed MAX limit like in arrays).
 * - Efficient insertions (O(1) at head) if we don't check for duplicates.
 * - However, to maintain Dictionary property (unique keys), we search first -> O(n).
 *
 * Operations:
 * 1. Insert: Add key-value pair (Update if key exists).
 * 2. Search: Find value by key.
 * 3. Delete: Remove node with given key.
 *
 * Time Complexity:
 * - Insert: O(n) (Traverse to check duplicate, then insert)
 * - Search: O(n) (Linear Traversal)
 * - Delete: O(n) (Find and remove)
 *
 * Space Complexity: O(n) (One node per element)
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Function Prototypes
void insert(Node** head, int key, int value);
int search(Node* head, int key);
void deleteKey(Node** head, int key);
void display(Node* head);

int main() {
    Node* head = NULL;
    int choice, key, value;

    while (1) {
        printf("\n--- Dictionary ADT (Linked List Implementation) ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(&head, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int val = search(head, key);
                if (val != -1) {
                    printf("Key found! Value: %d\n", val);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(&head, key);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Insert (or update) a key-value pair
void insert(Node** head, int key, int value) {
    Node* temp = *head;

    // Check if key already exists
    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key %d exists. Updating value.\n", key);
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed!\n");
        return;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = *head; // Insert at head for O(1) considering we already traversed
    *head = newNode;
    printf("Inserted (%d, %d)\n", key, value);
}

// Search for a key
int search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Not found
}

// Delete a key
void deleteKey(Node** head, int key) {
    Node *temp = *head, *prev = NULL;

    // Case 1: Head node holds the key
    if (temp != NULL && temp->key == key) {
        *head = temp->next;
        free(temp);
        printf("Key %d deleted.\n", key);
        return;
    }

    // Case 2: Search for key in rest of the list
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // Unlink and free
    prev->next = temp->next;
    free(temp);
    printf("Key %d deleted.\n", key);
}

// Display dictionary
void display(Node* head) {
    if (head == NULL) {
        printf("Dictionary is empty.\n");
        return;
    }
    printf("Dictionary Contents:\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("[%d : %d] -> ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Time Complexity (Average & Worst Case):
// Insert: O(n) (To check for duplicates)
// Search: O(n) (Worst case traverse all nodes)
// Delete: O(n) (Worst case traverse all nodes)
//
// Space Complexity: O(n) (Nodes)
