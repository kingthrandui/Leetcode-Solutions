class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // If the next character is also ')',
                // we have a complete pair of closing brackets.
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                // If no '(' is available, insert one '('.
                if (open > 0) {
                    open--;
                } 
                else {
                    ans++;
                }
            }
        }

        // Each remaining '(' needs two ')'.
        ans += open * 2;

        return ans;
    }
};