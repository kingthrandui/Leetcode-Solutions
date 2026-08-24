class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Convert stones into prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Initially, take all stones
        int dp = stones[n - 1];

        // Try all possible prefix positions from right to left
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};