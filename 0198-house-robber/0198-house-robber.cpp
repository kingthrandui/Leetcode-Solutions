class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // vector<int> dp(n+2,0);

        // dp[n-1] = nums[n-1];

        int next1 = nums[n-1];
        int next2 = 0;


        for(int i = n-2;i>=0;i--){
            int pick= nums[i]+next2;
            int not_pick = next1;

            int curr = max(pick, not_pick);

            
            next2 = next1;
            next1=curr;
        }

        return next1;;

    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1)
//             return nums[0];

//         vector<int> dp(n + 2, 0);

//         dp[n - 1] = nums[n - 1];

//         for (int i = n - 2; i >= 0; i--) {
//             int pick = nums[i] + dp[i + 2];
//             int notPick = dp[i + 1];

//             dp[i] = max(pick, notPick);
//         }

//         return dp[0];
//     }
// };