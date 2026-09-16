class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> sum(n, vector<long long>(k + 1, 0));

        // 0 segments can always be made in 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            sum[i][0] = i + 1;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i < n; i++) {

                // Don't use point i
                dp[i][j] = dp[i - 1][j];

                // Make a segment ending at i
                if (i >= 1) {
                    dp[i][j] += sum[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }

                // Prefix sum
                sum[i][j] = sum[i - 1][j] + dp[i][j];
                sum[i][j] %= MOD;
            }
        }

        return dp[n - 1][k];
    }
};