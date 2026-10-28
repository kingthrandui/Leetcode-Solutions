#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j] will store the set of possible XOR values for the current row at column j
        std::vector<std::unordered_set<int>> dp(n);
        
        for (int i = 0; i < m; ++i) {
            std::vector<std::unordered_set<int>> next_dp(n);
            for (int j = 0; j < n; ++j) {
                std::unordered_set<int> current_set;
                
                // From top cell (if valid)
                if (i > 0) {
                    for (int val : dp[j]) {
                        current_set.insert(val ^ grid[i][j]);
                    }
                }
                
                // From left cell (if valid)
                if (j > 0) {
                    for (int val : next_dp[j - 1]) {
                        current_set.insert(val ^ grid[i][j]);
                    }
                }
                
                // Base case for the start cell (0, 0)
                if (i == 0 && j == 0) {
                    current_set.insert(grid[0][0]);
                }
                
                next_dp[j] = std::move(current_set);
            }
            dp = std::move(next_dp);
        }
        
        // Find the minimum XOR value at the bottom-right cell (n - 1)
        int min_xor = *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
        return min_xor;
    }
};