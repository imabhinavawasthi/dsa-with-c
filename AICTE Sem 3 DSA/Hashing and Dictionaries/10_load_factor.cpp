/*
 * File: 10_load_factor.cpp
 * Author: Abhinav Awasthi
 *
 * Description:
 * This program demonstrates LOAD FACTOR (alpha) and its impact on Hash Table performance.
 *
 * Simulation:
 * We use a Linear Probing Hash Table of size 20.
 * We insert elements and count how many "Probes" (checks) are required.
 *
 * Purpose:
 * To visually demonstrate why we need to keep Load Factor low (e.g., < 0.7).
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define SIZE 20

enum Status { EMPTY, OCCUPIED };

struct HashSlot {
    int key;
    Status status;

    HashSlot() {
        status = EMPTY;
    }
};

class LoadFactorDemo {
private:
    HashSlot table[SIZE];

public:
    // Returns number of probes required to insert 'key'
    int insertWithProbes(int key) {
        int index = key % SIZE;
        int probes = 0;

        while (table[index].status == OCCUPIED) {
            probes++;
            index = (index + 1) % SIZE;
        }

        probes++; // Final check/insertion count
        table[index].key = key;
        table[index].status = OCCUPIED;
        return probes;
    }
};

int main() {
    LoadFactorDemo demo;
    
    // Test Data
    vector<int> keys = {10, 30, 50, 70, 90, 110, 130, 25, 45, 65, 85, 105, 12, 32, 52, 72, 92, 112, 132}; 

    cout << "\n--- Load Factor Demonstration (Table Size = " << SIZE << ") ---" << endl;
    cout << "| " << setw(10) << "Elements" << " | " << setw(12) << "Load Factor" << " | " << setw(15) << "Probes Needed" << " |" << endl;
    cout << "|------------|--------------|-----------------|" << endl;

    for (int i = 0; i < keys.size(); i++) {
        int probes = demo.insertWithProbes(keys[i]);
        float alpha = (float)(i + 1) / SIZE;

        cout << "| " << setw(10) << (i + 1) 
             << " | " << setw(12) << fixed << setprecision(2) << alpha 
             << " | " << setw(15) << probes << " |" << endl;
    }

    cout << "\nOBSERVATION:" << endl;
    cout << "As Load Factor (alpha) increases, the number of 'Probes Needed' grows significantly." << endl;
    cout << "This confirms that performance degrades as the table fills up." << endl;

    return 0;
}
