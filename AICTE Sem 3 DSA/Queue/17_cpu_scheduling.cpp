// File: 17_cpu_scheduling.cpp
// Title: Simple CPU Scheduling using Queue (C++)
// Author: Abhinav Awasthi
// Meaning details:
// - Simulates FCFS Scheduling.
// - Uses a Queue Class.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 5

struct Process {
    char name[10];
    int burstTime;
};

class Scheduler {
    Process arr[MAX];
    int front, rear;

public:
    Scheduler() {
        front = -1;
        rear = -1;
    }

    void addProcess(char name[], int burstTime) {
        if (rear == MAX - 1) {
            cout << "Ready Queue Full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        
        rear++;
        strcpy(arr[rear].name, name);
        arr[rear].burstTime = burstTime;
        cout << "Process " << name << " added (Burst: " << burstTime << ")." << endl;
    }

    void run() {
        cout << "\n--- Starting Execution ---\n";
        if (front == -1) {
            cout << "No processes." << endl;
            return;
        }

        while (front != -1 && front <= rear) {
            cout << "Exec " << arr[front].name << " (" << arr[front].burstTime << " units)... Done." << endl;
            front++;
        }
        
        front = -1;
        rear = -1;
        cout << "All Finished." << endl;
    }
};

int main() {
    Scheduler cpu;

    cout << "\n--- CPU Scheduling (C++) ---\n";
    
    cpu.addProcess((char*)"P1", 5);
    cpu.addProcess((char*)"P2", 2);
    cpu.addProcess((char*)"P3", 10);

    cpu.run();

    return 0;
}

// Time Complexity:
// - O(n)

// Space Complexity:
// - O(n)
