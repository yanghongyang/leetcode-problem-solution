/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 2;
        int left_state = dfs(root->left);
        int right_state = dfs(root->right);
        if (left_state == 0 || right_state == 0)
        {
            ans++;
            return 1;
        }
        else if (left_state == 1 || right_state == 1)
            return 2;
        else
            return 0;
    }
    int minCameraCover(TreeNode *root)
    {
        return dfs(root) == 0 ? ans + 1 : ans;
    }
};
// @lc code=end
