#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Validate palindrome possibility
        int odd_count = 0;
        char mid_char = 0;
        vector<int> half_count(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
            half_count[i] = count[i] / 2;
        }

        if (odd_count > 1) {
            return "";
        }

        int half_len = n / 2;

        // Try prefix match length 'i' of target's first half (from longest to shortest)
        for (int i = half_len; i >= 0; --i) {
            // Check if target[0...i-1] can be formed using half_count
            vector<int> cur_half = half_count;
            bool possible = true;
            string prefix = "";

            for (int j = 0; j < i; ++j) {
                int char_idx = target[j] - 'a';
                if (cur_half[char_idx] <= 0) {
                    possible = false;
                    break;
                }
                cur_half[char_idx]--;
                prefix += target[j];
            }

            if (!possible) continue;

            // Case 1: Exact match on first half (i == half_len)
            if (i == half_len) {
                string full_pal = prefix;
                if (n % 2 != 0) full_pal += mid_char;
                string rev = prefix;
                reverse(rev.begin(), rev.end());
                full_pal += rev;

                if (full_pal > target) {
                    return full_pal;
                }
                continue;
            }

            // Case 2: i < half_len, choose character strictly greater than target[i]
            int target_char_idx = target[i] - 'a';
            for (int next_char = target_char_idx + 1; next_char < 26; ++next_char) {
                if (cur_half[next_char] > 0) {
                    vector<int> rem_half = cur_half;
                    rem_half[next_char]--;

                    string res_half = prefix;
                    res_half += (char)('a' + next_char);

                    // Fill remaining positions greedily with smallest available characters
                    for (int c = 0; c < 26; ++c) {
                        while (rem_half[c] > 0) {
                            res_half += (char)('a' + c);
                            rem_half[c]--;
                        }
                    }

                    // Form full palindrome
                    string full_pal = res_half;
                    if (n % 2 != 0) full_pal += mid_char;
                    string rev = res_half;
                    reverse(rev.begin(), rev.end());
                    full_pal += rev;

                    return full_pal;
                }
            }
        }

        return "";
    }
};