#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // last_pos[j] stores the smallest index in word1 from which 
        // the suffix word2[j...m-1] can be matched exact (no changes).
        vector<int> last_pos(m, -1);
        int ptr = n - 1;

        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr < 0) break; // Cannot match the rest of the suffix
            last_pos[j] = ptr;
            ptr--; // Move pointer left for the next character in word2
        }

        vector<int> seq;
        seq.reserve(m);
        bool changed = false;
        int i = 0;

        for (int j = 0; j < m; ++j) {
            // Find the first index in word1 >= i that can match word2[j]
            while (i < n) {
                bool is_match = (word1[i] == word2[j]);
                
                // Can we use our 1 replacement here?
                bool can_change = !changed && (
                    (j + 1 == m) || (i + 1 <= last_pos[j + 1])
                );

                if (is_match || can_change) {
                    if (!is_match) {
                        changed = true; // Use up our 1 allowed replacement
                    }
                    seq.push_back(i);
                    i++; // Next index in word1 must be strictly greater
                    break;
                }
                i++;
            }

            // If we couldn't match word2[j] at all, no valid sequence exists
            if (seq.size() <= j) {
                return {};
            }
        }

        return seq;
    }
};