// File: 16_printer_queue.cpp
// Title: Printer Queue Simulation (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Simulates FIFO printing logic.
// - Uses Queue Class with Job struct.

#include <iostream>
using namespace std;

#define MAX 5

struct Job {
    int id;
    int pages;
};

class PrinterQueue {
    Job arr[MAX];
    int front, rear;

public:
    PrinterQueue() {
        front = -1;
        rear = -1;
    }

    void addJob(int id, int pages) {
        if (rear == MAX - 1) {
            cout << "Printer Buffer Full! Waiting for jobs to clear." << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear].id = id;
        arr[rear].pages = pages;
        cout << "Job " << id << " added." << endl;
    }

    void processJob() {
        if (front == -1 || front > rear) {
            cout << "No jobs to print." << endl;
            return;
        }
        cout << "Printing Job ID: " << arr[front].id << " (" << arr[front].pages << " pages)... Done." << endl;
        front++;
    }

    void displayPending() {
        if (front == -1 || front > rear) {
            cout << "No pending jobs." << endl;
            return;
        }
        cout << "Pending Jobs: ";
        for (int i = front; i <= rear; i++) {
            cout << "[ID:" << arr[i].id << "] ";
        }
        cout << endl;
    }
};

int main() {
    PrinterQueue pq;
    int choice, id, pages;

    cout << "\n--- Printer Queue Simulation (C++) ---\n";
    cout << "1. Add Job\n";
    cout << "2. Process Job\n";
    cout << "3. View Pending\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> id;
                cout << "Enter Pages: ";
                cin >> pages;
                pq.addJob(id, pages);
                break;
            case 2:
                pq.processJob();
                break;
            case 3:
                pq.displayPending();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

// Time Complexity:
// - O(1)

// Space Complexity:
// - O(n)
