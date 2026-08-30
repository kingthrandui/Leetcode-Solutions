class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int st = 0;
        int end = nums.size();

        int min = 0;
        int max = 0;

        if (end == 1)
            return 1;

        // Find min and max indices
        for (int i = 0; i < end; i++) {

            if (nums[i] < nums[min])
                min = i;

            if (nums[i] > nums[max])
                max = i;
        }

        // Make min come before max
        if (min > max)
            swap(min, max);

        // Your left/right calculations

        // Both from left
        int left = max + 1;

        // Both from right
        int right = end - min;

        // Min from left, max from right
        int middle = (min + 1) + (end - max);

        return std::min({left, right, middle});
    }
};