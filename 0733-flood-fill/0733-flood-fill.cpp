class Solution {
public:
    void dfs(vector<vector<int>>& image,int i , int j , int newcolour, int orgcolour){
        if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]==newcolour||image[i][j]!=orgcolour){
            return;
        }
        image[i][j] = newcolour;
        dfs(image,i,j+1,newcolour,orgcolour);//right
        dfs(image,i+1,j,newcolour,orgcolour);//bottom
        dfs(image,i,j-1,newcolour,orgcolour);//left
        dfs(image,i-1,j,newcolour,orgcolour);//top;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};