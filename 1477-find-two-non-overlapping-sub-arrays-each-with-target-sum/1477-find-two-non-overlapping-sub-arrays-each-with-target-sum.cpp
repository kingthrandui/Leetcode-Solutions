class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // best[i] = minimum length of a valid subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);
        
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            // If current window has sum = target
            if (sum == target) {
                int len = right - left + 1;
                
                // Need another subarray before this one
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }
                
                // Store the shortest subarray found so far
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {
                // No valid subarray ending at right
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }
        
        if (ans == INT_MAX)
            return -1;
            
        return ans;
    }
};