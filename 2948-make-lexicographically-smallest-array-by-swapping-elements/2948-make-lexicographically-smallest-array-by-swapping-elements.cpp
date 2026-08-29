class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // {value, original index}
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort according to value
        sort(v.begin(), v.end());

        vector<int> ans = nums;

        int i = 0;

        while (i < n) {

            int j = i;

            // Find one connected group
            while (j + 1 < n &&
                   v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(v[k].second);
            }

            // Original indices should be sorted
            sort(indices.begin(), indices.end());

            // Values are already sorted because v is sorted
            for (int k = i; k <= j; k++) {
                ans[indices[k - i]] = v[k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};