class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for (int i = 0; i < num; i++) {
            int start = (i==0)? 9: 9;
                for (int j = start; j >= 0; j--) {
                    if (sum >= j) {
                        ans += to_string(j);
                        sum -= j;
                        break;
                    }
                }
            }

            if (sum == 0 && ans.size() == num) {
                return ans;
            }

        return "";
    }
};