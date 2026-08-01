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
    int search(vector<int>& inorder, int left, int right, int value) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int& preIndex,
    int left,int right) {

        if (left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIndex]);

        int inIndex = search(inorder, left, right, preorder[preIndex]);

        preIndex++;

        root->left = helper(preorder, inorder, preIndex, left, inIndex - 1);

        root->right = helper(preorder, inorder, preIndex, inIndex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;

        return helper(
            preorder,
            inorder,
            preIndex,
            0,
            inorder.size() - 1
        );
    }
};