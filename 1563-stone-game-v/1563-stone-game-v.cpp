#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // prefix[i] = sum of first i elements
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score Alice can get
        // from subarray [l...r]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of subarray
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                // Try every possible split
                for (int k = l; k < r; k++) {

                    // Sum of left part
                    int left = prefix[k + 1] - prefix[l];

                    // Sum of right part
                    int right = prefix[r + 1] - prefix[k + 1];

                    if (left < right) {

                        // Right is thrown away
                        // Alice keeps left
                        dp[l][r] = max(
                            dp[l][r],
                            left + dp[l][k]
                        );

                    }
                    else if (left > right) {

                        // Left is thrown away
                        // Alice keeps right
                        dp[l][r] = max(
                            dp[l][r],
                            right + dp[k + 1][r]
                        );

                    }
                    else {

                        // Equal sums
                        // Alice chooses the better side
                        dp[l][r] = max(
                            dp[l][r],
                            left + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};