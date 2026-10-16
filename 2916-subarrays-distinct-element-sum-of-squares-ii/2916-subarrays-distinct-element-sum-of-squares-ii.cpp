#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    
    vector<long long> sumSq, sumVal, lazy;
    
    void pushDown(int node, int l, int r) {
        if (lazy[node] == 0) return;
        int mid = l + (r - l) / 2;
        apply(2 * node, l, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }
    
    void apply(int node, int l, int r, long long v) {
        long long len = (r - l + 1);
        v %= MOD;
        // (x + v)^2 = x^2 + 2*v*x + v^2 * len
        long long addSq = (2 * v % MOD * sumVal[node] % MOD + v * v % MOD * (len % MOD)) % MOD;
        sumSq[node] = (sumSq[node] + addSq) % MOD;
        sumVal[node] = (sumVal[node] + v * (len % MOD)) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }
    
    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, v);
            return;
        }
        pushDown(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, v);
        update(2 * node + 1, mid + 1, r, ql, qr, v);
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        sumVal[node] = (sumVal[2 * node] + sumVal[2 * node + 1]) % MOD;
    }
    
    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return sumSq[node];
        pushDown(node, l, r);
        int mid = l + (r - l) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sumSq.assign(4 * n, 0);
        sumVal.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        unordered_map<int, int> lastPos;
        long long totalSum = 0;
        
        for (int j = 0; j < n; ++j) {
            int last = lastPos.count(nums[j]) ? lastPos[nums[j]] : -1;
            lastPos[nums[j]] = j;
            
            // Update range [last + 1, j] by adding 1 to distinct counts
            update(1, 0, n - 1, last + 1, j, 1);
            
            // The sum of squares of all subarrays ending at index j is query(0 to j)
            long long currentSubarraySquares = query(1, 0, n - 1, 0, j);
            totalSum = (totalSum + currentSubarraySquares) % MOD;
        }
        
        return totalSum;
    }
};