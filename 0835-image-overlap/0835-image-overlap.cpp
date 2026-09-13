class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        // Shift img1 by rowShift and colShift
        for (int rowShift = -n + 1; rowShift <= n - 1; rowShift++) {
            for (int colShift = -n + 1; colShift <= n - 1; colShift++) {

                int count = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        // Only consider 1s in img1
                        if (img1[i][j] == 1) {

                            int x = i + rowShift;
                            int y = j + colShift;

                            // Check whether translated position is inside
                            if (x >= 0 && x < n && y >= 0 && y < n) {

                                // Check overlap
                                if (img2[x][y] == 1) {
                                    count++;
                                }
                            }
                        }
                    }
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};