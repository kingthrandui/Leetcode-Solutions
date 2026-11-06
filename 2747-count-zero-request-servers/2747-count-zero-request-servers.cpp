#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // Sort logs by their timestamp
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        // Pair each query with its original index to restore order later
        vector<pair<int, int>> indexed_queries(m);
        for (int i = 0; i < m; ++i) {
            indexed_queries[i] = {queries[i], i};
        }
        sort(indexed_queries.begin(), indexed_queries.end());

        vector<int> ans(m);
        unordered_map<int, int> server_counts;

        int log_idx = 0;
        int window_start = 0;
        int num_logs = logs.size();

        // Process each query in sorted order
        for (const auto& [q, original_idx] : indexed_queries) {
            int window_end_time = q;
            int window_start_time = q - x;

            // 1. Add all logs whose time is <= window_end_time
            while (log_idx < num_logs && logs[log_idx][1] <= window_end_time) {
                server_counts[logs[log_idx][0]]++;
                log_idx++;
            }

            // 2. Remove all logs whose time is < window_start_time
            while (window_start < log_idx && logs[window_start][1] < window_start_time) {
                int server_id = logs[window_start][0];
                server_counts[server_id]--;
                if (server_counts[server_id] == 0) {
                    server_counts.erase(server_id);
                }
                window_start++;
            }

            // 3. Total servers minus active servers gives zero-request servers
            ans[original_idx] = n - server_counts.size();
        }

        return ans;
    }
};