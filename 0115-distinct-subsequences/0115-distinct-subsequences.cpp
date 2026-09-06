#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int n = s.length();
        int m = t.length();

        // dp[j] holds the number of distinct subsequences of s that match t[0...j-1]
        // Using unsigned long long to prevent integer overflow during intermediate additions
        std::vector<unsigned long long> dp(m + 1, 0);

        // Base case: empty t can always be formed 1 way
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            // Iterate backwards to use values from the previous state of s
            for (int j = m; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};