class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int mid = n / 2;

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // Left half
        for (int i = 0; i < mid; i++) {
            if (num[i] == '?') {
                leftQ++;
            }
            else {
                leftSum += num[i] - '0';
            }
        }

        // Right half
        for (int i = mid; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            }
            else {
                rightSum += num[i] - '0';
            }
        }

        // Odd number of question marks
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        // Bob wins only if he can make both sums equal
        return leftSum - rightSum != (rightQ - leftQ) / 2 * 9;
    }
};