class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0")
            return "0";

        string ans = "0";

        int j = num2.length() - 1;

        while (j >= 0) {
            
            int i = num1.length() - 1;
            int carry = 0;
            string new_ans = "";

            while (i >= 0) {
                
                int mul = (num2[j] - '0') * (num1[i] - '0') + carry;

                new_ans = new_ans + char(mul % 10 + '0');

                carry = mul / 10;

                i--;
            }

            if (carry > 0)
                new_ans = new_ans + char(carry + '0');

            // Reverse because we built it backwards
            reverse(new_ans.begin(), new_ans.end());

            // Add zeros according to position
            int zeros = num2.length() - 1 - j;

            new_ans += string(zeros, '0');

            // Add new_ans to ans
            string temp = "";
            int p = ans.length() - 1;
            int q = new_ans.length() - 1;
            carry = 0;

            while (p >= 0 || q >= 0 || carry) {

                int sum = carry;

                if (p >= 0)
                    sum += ans[p--] - '0';

                if (q >= 0)
                    sum += new_ans[q--] - '0';

                temp += char(sum % 10 + '0');
                carry = sum / 10;
            }

            reverse(temp.begin(), temp.end());
            ans = temp;

            j--;
        }

        return ans;
    }
};