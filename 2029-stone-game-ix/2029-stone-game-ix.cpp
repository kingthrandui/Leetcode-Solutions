#include <vector>
#include <numeric>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        
        // Count frequencies of stones modulo 3
        for (int s : stones) {
            if (s % 3 == 0) c0++;
            else if (s % 3 == 1) c1++;
            else c2++;
        }
        
        // If there are no stones of type 1 or 2, the sum can never reach a 
        // multiple of 3 (unless the first stone is 0, which isn't allowed to start).
        // If there are only 0s, Alice immediately loses or cannot make a move.
        if (c1 == 0 && c2 == 0) return false;
        
        // Strategy:
        // If c0 is even:
        // We can win if we have at least 3 of either 1s or 2s (e.g., 1, 1, 2... or 2, 2, 1...)
        // effectively forcing the other player to pick the one that makes the sum divisible by 3.
        if (c0 % 2 == 0) {
            return c1 >= 1 && c2 >= 1;
        } 
        // If c0 is odd:
        // The parity of c0 allows us to use the 0s to flip turns.
        // We win if the difference between c1 and c2 is greater than 2.
        else {
            return std::abs(c1 - c2) > 2;
        }
    }
};