// Solution2.cpp
// Problem: Accumulator Apex
//
// Approach:
// - For each list, calculate prefix sums and minimum prefix.
// - Greedily select the list with maximum usable gain.
// - Repeat until no valid list remains.
//
// Time Complexity: O(N)
// Space Complexity: O(N)
//
// Submission Link:
// https://github.com/yogesh4216/CP-Chronicles/blob/day04-accumulator/Problems/Data-structures/Day-04/sol/yogesh/Solution2.cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    int k;
    cin >> x >> k;

    vector<vector<long long>> lists(k);
    for (int i = 0; i < k; i++) {
        int len;
        cin >> len;
        lists[i].resize(len);
        for (int j = 0; j < len; j++) {
            cin >> lists[i][j];
        }
    }

    vector<bool> used(k, false);

    while (true) {
        long long bestGain = 0;
        int bestIdx = -1;

        for (int i = 0; i < k; i++) {
            if (used[i]) continue;

            long long sum = 0;
            long long minPrefix = 0;

            for (long long v : lists[i]) {
                sum += v;
                minPrefix = min(minPrefix, sum);
            }

            if (x + minPrefix >= 0 && sum > bestGain) {
                bestGain = sum;
                bestIdx = i;
            }
        }

        if (bestIdx == -1)
            break;

        x += bestGain;
        used[bestIdx] = true;
    }

    cout << x << "\n";
    return 0;
}