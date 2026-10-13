class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i] = -(nums[i]);
            }
        }
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i<n;i++){
            if(count<n/2){
                ans -= nums[i]*nums[i];
                count++;
            }
            else{
                ans += nums[i]*nums[i];
            }
        }
        return ans;
    }
};