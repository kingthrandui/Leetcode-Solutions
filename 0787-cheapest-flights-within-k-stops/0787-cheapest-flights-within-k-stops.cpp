class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> graph[n];

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q; // {src, {distance, stops}}

        vector<int> dist(n, INT_MAX);

        q.push({src, {0, -1}});
        dist[src] = 0;
        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int u = curr.first;
            int dis = curr.second.first;
            int stops = curr.second.second;

            for (auto edge : graph[u]) {

                int v = edge.first;
                int wt = edge.second;

                if (dis + wt < dist[v] && stops + 1 <= k) {

                    dist[v] = dis + wt;

                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};