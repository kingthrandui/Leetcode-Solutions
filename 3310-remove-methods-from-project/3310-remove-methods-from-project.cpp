class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto& invo : invocations) {
            adj[invo[0]].push_back(invo[1]);
        }

        vector<int> sus(n, 0);
        queue<int> q;

        q.push(k);
        sus[k] = 1;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v : adj[u]) {

                if (!sus[v]) {
                    sus[v] = 1;
                    q.push(v);
                }
            }
        }

        for (auto& invo : invocations) {

            int u = invo[0];
            int v = invo[1];

            if (!sus[u] && sus[v]) {

                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};