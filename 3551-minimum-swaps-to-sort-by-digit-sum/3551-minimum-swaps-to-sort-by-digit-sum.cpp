// class Solution {
// public:
//     int digit(int n){
//         int sum = 0;
//         while(n>0){
//             sum = sum+n%10;
//             n = n/10;
//         }
//         return sum;
//     }
//     int minSwaps(vector<int>& nums) {
//         vector<int> arr;
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0;i<nums.size();i++){
//             int Sum  = digit(nums[i]);
//             arr.push_back(Sum);
//         }
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = 0; j < n - i - 1; j++) {
//                 if (arr[j] > arr[j + 1]) {
//                     count++;
//                     swap(arr[j], arr[j + 1]);
                    
//                 }
//             }
//         }
//         return count;
        
//     }
// };
class Solution {
public:
    int digit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({{digit(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[i] == i) {
                continue;
            }

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                cycle++;
            }

            if (cycle > 1) {
                swaps += cycle - 1;
            }
        }

        return swaps;
    }
};