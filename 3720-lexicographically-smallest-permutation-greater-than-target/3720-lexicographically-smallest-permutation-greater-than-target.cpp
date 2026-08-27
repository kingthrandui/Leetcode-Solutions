class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int n = s.length();

        // Store the state at positions where
        // we can choose a character > target[i]
        int bestPos = -1;
        vector<int> bestFreq;

        for (int i = 0; i < n; i++) {

            // Before matching target[i], check whether
            // there is any available character greater than it
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    bestPos = i;
                    bestFreq = freq;
                    break;
                }
            }

            // Try to match target[i]
            int curr = target[i] - 'a';

            if (freq[curr] == 0) {
                break;
            }

            freq[curr]--;
        }

        // If we matched the entire target, then target itself
        // is a permutation of s. We still need STRICTLY greater.
        if (bestPos == -1) {
            return "";
        }

        // Restore frequency at the best position
        freq = bestFreq;

        string ans = target.substr(0, bestPos);

        // Choose smallest character > target[bestPos]
        for (int c = target[bestPos] - 'a' + 1; c < 26; c++) {
            if (freq[c] > 0) {
                ans += char('a' + c);
                freq[c]--;
                break;
            }
        }

        // Add remaining characters in sorted order
        for (int c = 0; c < 26; c++) {
            while (freq[c] > 0) {
                ans += char('a' + c);
                freq[c]--;
            }
        }

        return ans;
    }
};