class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> a1;
        vector<int> a2;
        vector<int> ans;

        if (nums.size() == 2) {
            return nums;
        }

        // Start with first two elements
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);

        int last1 = nums[0];
        int last2 = nums[1];

        // Start from index 2
        for (int i = 2; i < nums.size(); i++) {

            if (last1 > last2) {
                a1.push_back(nums[i]);
                last1 = nums[i];
            }
            else {
                a2.push_back(nums[i]);
                last2 = nums[i];
            }
        }

        // Combine a1 and a2
        for (int i = 0; i < a1.size(); i++) {
            ans.push_back(a1[i]);
        }

        for (int i = 0; i < a2.size(); i++) {
            ans.push_back(a2[i]);
        }

        return ans;
    }
};