/*
Problem: Room Allocation
Link: https://cses.fi/problemset/task/1164
Author: Krishna Sikheriya (Krishna200608)

Short Problem Statement:
There is a hotel and n customers with specific arrival and departure times. 
We need to assign rooms to customers such that the total number of rooms used is minimized.
Two customers can stay in the same room if the first customer leaves before the second arrives.
Print the minimum number of rooms needed and the room assignment for each customer.

Approach:
1. Store customer details (arrival, departure, original_index).
2. Sort customers based on arrival times.
3. Use a Min-Priority Queue (Min-Heap) to store pairs of {departure_time, room_number} for currently occupied rooms.
   The heap allows us to efficiently find the room that becomes free earliest.
4. Iterate through the sorted customers:
   - If the earliest departure time in the heap is less than the current customer's arrival time, 
     it means that room is free. We reuse that room (pop from heap).
   - If no room is free, we allocate a new room number.
   - Push the current customer's departure time and assigned room number into the heap.
   - Store the assigned room number in an answer array using the original index.
5. The maximum size of the heap reached (or the max room ID generated) gives the minimum rooms required.

Time Complexity: O(N log N) - dominated by sorting the customers. Heap operations take O(log N).
Space Complexity: O(N) - to store customer details, the priority queue, and the answer array.

Example I/O:
Input:
3
1 2
2 4
4 4

Output:
2
1 2 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Struct to keep track of customer details and their original order
struct Customer {
    int id;
    int arrival;
    int departure;
};

// Comparator to sort customers by arrival time
bool compareCustomers(const Customer& a, const Customer& b) {
    return a.arrival < b.arrival;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Customer> customers(n);
    for (int i = 0; i < n; ++i) {
        customers[i].id = i;
        cin >> customers[i].arrival >> customers[i].departure;
    }

    sort(customers.begin(), customers.end(), compareCustomers);

    // Min-priority queue to store {departure_time, room_number}
    // We want the room that frees up earliest to be at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> ans(n);
    int last_room_id = 0;

    for (int i = 0; i < n; ++i) {
        int assigned_room;

        // Check if the earliest departing room is free before current arrival
        if (!pq.empty() && pq.top().first < customers[i].arrival) {
            assigned_room = pq.top().second;
            pq.pop();
        } else {
            // Allocate a new room
            last_room_id++;
            assigned_room = last_room_id;
        }

        // Push current customer's departure and room info
        pq.push({customers[i].departure, assigned_room});
        ans[customers[i].id] = assigned_room;
    }

    // Output results
    cout << last_room_id << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
SUBMISSION LINK:
https://cses.fi/paste/d01d5f0ab0c6ae25f11225/
*/