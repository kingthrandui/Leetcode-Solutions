/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxWidth = 0;

        while(!q.empty()){

            int left = q.front().second;
            int right = q.back().second;
            int maxi = (right-left)+1;

            maxWidth = max(maxWidth,maxi);
            int n = q.size();
            for(int i = 0;i<n;i++){
                long long idx = q.front().second;

                
                TreeNode* node = (q.front().first);
                idx = idx-left;
                q.pop();
                if(node->left){
                    q.push({node->left,2*idx+1});
                }
                if(node->right){
                    q.push({node->right,2*idx+2});
                }
            }
        }
        return maxWidth;
    }
};