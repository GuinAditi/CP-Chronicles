#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i; // original index
    }

    // Sort by arrival time
    sort(customers.begin(), customers.end());

    // Min-heap: (departure day, room number)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> roomAssigned(n);
    int rooms = 0;

    for (auto &[start, end, idx] : customers) {
        if (!pq.empty() && pq.top().first < start) {
            // Reuse room
            auto [dep, room] = pq.top();
            pq.pop();
            roomAssigned[idx] = room;
            pq.push({end, room});
        } else {
            // Need new room
            rooms++;
            roomAssigned[idx] = rooms;
            pq.push({end, rooms});
        }
    }

    cout << rooms << "\n";
    for (int i = 0; i < n; i++) {
        cout << roomAssigned[i] << " ";
    }

    return 0;
}
