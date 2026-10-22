#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int zero = std::find(nums.begin(), nums.end(), 0) - nums.begin();
        
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };
        
        int ans = INT_MAX;
        
        // Case A: Increasing to the right (step = 1)
        if (check(1)) {
            ans = std::min(ans, zero);         // Pure left rotations
            ans = std::min(ans, n - zero + 2); // Reverse + rotate + reverse path
        }
        
        // Case B: Increasing to the left / reversed order (step = -1)
        if (check(-1)) {
            ans = std::min(ans, zero + 2);     // Rotate + reverse path
            ans = std::min(ans, n - zero);     // Reverse + rotate path
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};