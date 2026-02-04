/*
 * Program: 13. Count frequency of elements
 * Language: C++
 * Description: Counts how many times each element appears in the array.
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 10, 30, 20, 10, 40};
    int n = 7;
    int visited[7]; // To mark visited elements
    
    // Initialize visited array to 0
    for(int i = 0; i < n; i++) visited[i] = 0;

    cout << "Element | Frequency" << endl;
    cout << "-------------------" << endl;

    for(int i = 0; i < n; i++) {
        // Skip if element is already processed
        if(visited[i] == 1) continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark duplicate as visited
            }
        }
        
        cout << "   " << arr[i] << "    |     " << count << endl;
    }

    return 0;
}

// Time Complexity: O(N^2) - Nested loops for counting.
// Space Complexity: O(N) - Visited array.
