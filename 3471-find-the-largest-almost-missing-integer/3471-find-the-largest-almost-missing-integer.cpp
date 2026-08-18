class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < k) {
            return -1;
        }

        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }

        vector<int> freq(1001, 0);

        int maxi = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        if (k == 1) {
            for (int i = maxi; i >= 0; i--) {
                if (freq[i] == 1) {
                    return i;
                }
            }
        }

        if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1) {
            return max(nums[0], nums[n - 1]);
        }

        if (freq[nums[0]] == 1) {
            return nums[0];
        }

        if (freq[nums[n - 1]] == 1) {
            return nums[n - 1];
        }

        return -1;
    }
};