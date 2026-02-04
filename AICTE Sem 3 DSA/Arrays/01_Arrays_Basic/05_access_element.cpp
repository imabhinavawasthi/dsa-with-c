/*
 * Program: 5. Demonstrate O(1) array access
 * Language: C++
 * Description: Shows that accessing any element by index is instant (Constant Time).
 * Author: Antigravity (Generated for DSA Repository)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] = {100, 200, 300, 400, 500};

    // Arrays are stored in contiguous memory.
    // Address of arr[i] = Base Address + (i * size_of_element)
    // This calculation happens instantly, O(1).

    cout << "Array: {100, 200, 300, 400, 500}" << endl;

    // Random access examples
    cout << "Accessing index 0: " << arr[0] << endl;
    cout << "Accessing index 3: " << arr[3] << endl;
    cout << "Accessing index 4: " << arr[4] << endl;

    return 0;
}

// Time Complexity: O(1) - Access speed does not depend on array size.
// Space Complexity: O(1) - No extra space used.
