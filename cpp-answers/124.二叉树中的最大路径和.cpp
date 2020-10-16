/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-17 07:53:10
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-17 07:56:11
 */
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
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
class Solution
{
public:
    int dfs(TreeNode *root, int &maxsum)
    {
        if (!root)
            return 0;
        int l = max(0, dfs(root->left, maxsum));
        int r = max(0, dfs(root->right, maxsum));
        maxsum = max(l + r + root->val, maxsum);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxsum = INT_MIN;
        dfs(root, maxsum);
        return maxsum;
    }
};
// @lc code=end
