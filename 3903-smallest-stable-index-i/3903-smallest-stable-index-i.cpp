class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi = nums[0];
        int mini = nums[0];

        while(i < n && j < n) {
            
            // Find maximum from 0 to i
            maxi = nums[0];
            for(int k = 0; k <= i; k++) {
                if(nums[k] > maxi) {
                    maxi = nums[k];
                }
            }

            // Find minimum from j to n-1
            mini = nums[j];
            for(int l = j; l < n; l++) {
                if(nums[l] < mini) {
                    mini = nums[l];
                }
            }

            int ans = maxi - mini;

            if(ans <= k) {
                return i;
            }

            i++;
            j++;
        }

        return -1;
    }
};