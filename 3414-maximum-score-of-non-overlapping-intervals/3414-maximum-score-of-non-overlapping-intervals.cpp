#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Node {
        int l, r, w, idx;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Node> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals primarily by start time, secondarily by original index
        sort(a.begin(), a.end(), [](const Node& x, const Node& y) {
            if (x.l != y.l) return x.l < y.l;
            return x.idx < y.idx;
        });

        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = a[i].l;

        // dp[i][k] stores {max_weight, vector_of_indices} considering suffix starting at i with k choices left
        struct State {
            long long score = 0;
            vector<int> indices;

            bool operator<(const State& other) const {
                if (score != other.score) return score < other.score;
                return indices > other.indices; // Smaller indices are better lexicographically
            }
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            // Find next non-overlapping interval: start > a[i].r
            int next = upper_bound(starts.begin(), starts.end(), a[i].r) - starts.begin();

            for (int k = 1; k <= 4; k++) {
                // Option 1: Skip interval i
                State best = dp[i + 1][k];

                // Option 2: Take interval i
                State take = dp[next][k - 1];
                take.score += a[i].w;
                take.indices.push_back(a[i].idx);
                sort(take.indices.begin(), take.indices.end());

                // Choose the best state according to weight, then lexicographical comparison
                if (best < take) {
                    best = take;
                }
                dp[i][k] = best;
            }
        }

        return dp[0][4].indices;
    }
};