class Solution {
public:

    bool iscycle(int src,
                 vector<bool>& vis,
                 vector<vector<int>>& prerequisites,
                 vector<bool>& recpath) {

        vis[src] = true;
        recpath[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {

            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            // u -> v
            if (u == src) {

                if (!vis[v]) {

                    if (iscycle(v, vis, prerequisites, recpath)) {
                        return true;
                    }

                }
                else if (recpath[v] == true) {
                    return true;
                }
            }
        }

        // DFS of this node is completely finished
        recpath[src] = false;

        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (iscycle(i, vis, prerequisites, recpath)) {
                    return false;   // cycle -> cannot finish
                }
            }
        }

        return true;   // no cycle -> can finish
    }
};