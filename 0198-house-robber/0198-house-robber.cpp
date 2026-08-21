class Solution {
public:
    int solve( int i ,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans1 = solve(i+1 , nums, dp);
        int ans2 = nums[i]+solve(i+2,nums,dp);
        return dp[i] = max(ans1,ans2);

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int result = solve(0,nums,dp);
        return result;
    }
};