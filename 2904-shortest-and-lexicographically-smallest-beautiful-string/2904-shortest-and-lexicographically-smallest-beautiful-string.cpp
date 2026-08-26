class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";
        int n = s.length();
        for(int right = 0;right<n;right++){
            if(s[right]=='1'){
                ones++;
            }

            while(ones>k){
                if(s[left]=='1'){
                    ones--;
                }
                left++;
            }
            while(ones==k && s[left]=='0'){
                    left++;
            }
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                if (ans == "" ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    
                    ans = curr;
                }
            }
        }
        return ans;
    }
};