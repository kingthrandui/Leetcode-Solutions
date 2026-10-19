
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int other = 0;
        vector<int> ans;

        for (int x : nums) {
            if (x < target) {
                count++;
            }
            else if (x == target) {
                other++;
            }
        }

        for (int i = 0; i < other; i++) {
            ans.push_back(count + i);
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<int>ans;
//         for(int i = 0;i<nums.size();i++){
//             if(nums[i]==target){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };