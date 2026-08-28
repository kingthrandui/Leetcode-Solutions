class Solution {
public:
    void dfs(int i ,vector<vector<int>>& isConnected,vector<bool> &vis ){
        vis[i] = true;
        for(int j = 0;j<isConnected[0].size();j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        int ans = 0;
        vector<bool> vis(n,false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans;
    }
};