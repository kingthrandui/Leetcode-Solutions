// class Solution {
// public:
//     int helper(vector<int>& piles, int start, int end) {
//         // Base case
//         if (start == end) {
//             return piles[start];
//         }
//         int takeLeft = piles[start] - helper(piles, start + 1, end);

        
//         int takeRight = piles[end] - helper(piles, start, end - 1);

//         return max(takeLeft, takeRight);
//     }

//     bool stoneGame(vector<int>& piles) {
//         return helper(piles, 0, piles.size() - 1) > 0;
//     }
// };
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};