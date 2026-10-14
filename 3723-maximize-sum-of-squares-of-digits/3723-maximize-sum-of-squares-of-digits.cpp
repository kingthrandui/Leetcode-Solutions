class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for (int i = 0; i < num; i++) {
            if (i == 0) {
                for (int j = 9; j > 0; j--) {
                    if (sum >= j) {
                        ans += to_string(j);
                        sum -= j;
                        break;
                    }
                }
            }
            else {
                for (int j = 9; j >= 0; j--) {
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
        }

        return "";
    }
};