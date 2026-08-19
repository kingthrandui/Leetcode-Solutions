class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> mp;
        
        // Store reserved seats row-wise
        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        // Initially, every row can accommodate 2 groups
        int ans = 2 * n;

        // Only rows having reservations need special checking
        for (auto &row : mp) {
            
            auto &reserved = row.second;
            
            // We assumed 2 groups for this row.
            // Now calculate the actual number.
            int groups = 0;

            bool left = true;   // seats 2,3,4,5
            bool middle = true; // seats 4,5,6,7
            bool right = true;  // seats 6,7,8,9

            // Check left block
            for (int s = 2; s <= 5; s++) {
                if (reserved.count(s)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int s = 4; s <= 7; s++) {
                if (reserved.count(s)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int s = 6; s <= 9; s++) {
                if (reserved.count(s)) {
                    right = false;
                    break;
                }
            }

            // If left and right are both available,
            // we can put 2 groups.
            if (left && right) {
                groups = 2;
            }
            // Otherwise, if any one block is available,
            // we can put 1 group.
            else if (left || middle || right) {
                groups = 1;
            }

            // We initially counted 2 for this row.
            // Replace it with the actual number.
            ans -= 2;
            ans += groups;
        }

        return ans;
    }
};