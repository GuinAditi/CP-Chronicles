/*
Problem: Nearest Smaller Values
Link: https://cses.fi/problemset/task/1645
Author: Krishna Sikheriya (Krishna200608)

Short Problem Statement:
Given an array of n integers, find for each array position the nearest position to its left having a smaller value. If no such position exists, print 0.

Approach:
We use a Monotonic Stack to solve this in linear time. 
The stack will store pairs of (value, index) and maintain an increasing order of values.
For each element in the array:
1. We pop elements from the stack that are greater than or equal to the current element, as they cannot be the nearest smaller value for the current or subsequent elements.
2. If the stack becomes empty, it means there is no smaller value to the left; we print 0.
3. If the stack is not empty, the top element is the nearest smaller value; we print its index.
4. We push the current element and its index onto the stack.

Time Complexity: O(n) - Each element is pushed and popped from the stack at most once.
Space Complexity: O(n) - In the worst case (increasing array), the stack stores all elements.

Example I/O:
Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    // Optimization for faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Stack stores pairs of {value, 1-based index}
    stack<pair<int, int>> s; 
    
    for (int i = 0; i < n; ++i) {
        // Pop elements greater than or equal to current element
        // We only care about smaller values to the left
        while (!s.empty() && s.top().first >= a[i]) {
            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        } else {
            cout << s.top().second << " ";
        }

        // Push current element (value, index) to stack
        s.push({a[i], i + 1});
    }
    cout << endl;

    return 0;
}

/*
SUBMISSION LINK: 
https://cses.fi/paste/b62e11edd0054b5cf11189/
*/