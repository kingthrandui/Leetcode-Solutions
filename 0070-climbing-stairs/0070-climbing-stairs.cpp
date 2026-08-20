class Solution {
public:
    vector<int>dp;
    int solve(int n , int i){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] = solve(n,i+1)+solve(n,i+2);
        return dp[i];
    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        int ans = solve(n,0);
        return ans;
    }
};