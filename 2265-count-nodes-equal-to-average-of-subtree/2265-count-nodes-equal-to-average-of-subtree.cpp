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

    int ans = 0;

    pair<int,int> cal(TreeNode* root) {

        if(root == NULL) {
            return {0, 0};
        }

        pair<int,int> l = cal(root->left);
        pair<int,int> r = cal(root->right);

        int sum = l.first + r.first + root->val;
        int count = l.second + r.second + 1;

        int avg = sum / count;

        if(avg == root->val) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        cal(root);

        return ans;
    }
};