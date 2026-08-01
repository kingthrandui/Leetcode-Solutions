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

        if (root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {

            int n = q.size();

            long long left = q.front().second;
            long long right = q.back().second;

            maxWidth = max(maxWidth, (int)(right - left + 1));

            for (int i = 0; i < n; i++) {

                auto node = q.front();
                long long idx = node.second - left;

                q.pop();

                if (node.first->left) {
                    q.push({node.first->left, 2 * idx + 1});
                }

                if (node.first->right) {
                    q.push({node.first->right, 2 * idx + 2});
                }
            }
        }

        return maxWidth;
    }
};