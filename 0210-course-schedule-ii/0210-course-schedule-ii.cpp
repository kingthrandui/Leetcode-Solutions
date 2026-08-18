class Solution {
public:

    bool isCycle(int src,
                 vector<bool> &vis,
                 vector<bool> &recPath,
                 vector<vector<int>>& prerequisites) {

        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {

            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            // u -> v
            if (u == src) {

                if (!vis[v]) {

                    if (isCycle(v, vis, recPath, prerequisites)) {
                        return true;
                    }

                }
                else if (recPath[v]) {
                    return true;
                }
            }
        }

        // DFS of this node is completely finished
        recPath[src] = false;

        return false;
    }


    void topo(int src,
              vector<bool> &vis,
              vector<vector<int>>& prerequisites,
              stack<int> &s) {

        vis[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {

            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            // u -> v
            if (u == src) {

                if (!vis[v]) {
                    topo(v, vis, prerequisites, s);
                }
            }
        }

        // Put node after all its neighbours
        s.push(src);
    }


    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        vector<int> ans;
        stack<int> s;


        // STEP 1: Check for cycle
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                if (isCycle(i, vis, recPath, prerequisites)) {
                    return ans;
                }
            }
        }


        // STEP 2: Reset visited array
        vis.assign(n, false);


        // STEP 3: Topological sort
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                topo(i, vis, prerequisites, s);
            }
        }


        // STEP 4: Convert stack to answer
        while (!s.empty()) {

            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};