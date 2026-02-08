// File: 9_pq_2_4_tree.cpp
// Purpose: Priority Queue using 2-4 Tree (Conceptual)
// Author: Abhinav Awasthi

#include <iostream>
using namespace std;

int main() {
    cout << "--- Priority Queue using 2-4 Tree ---" << endl;
    
    cout << "1. Implementation Idea:" << endl;
    cout << "   - Use a standard 2-4 Tree structure." << endl;
    cout << "   - Maintain sorted order of keys." << endl;

    cout << "2. Extract Minimum:" << endl;
    cout << "   - Iterate root->children[0] until leaf." << endl;
    cout << "   - Return keys[0] of that leaf." << endl;
    
    cout << "3. Complexity:" << endl;
    cout << "   - Time: O(log N) for both Insert and Delete." << endl;
    cout << "   - Space: O(N)." << endl;

    return 0;
}

// Time Complexity: O(log N)
// Space Complexity: O(N)
