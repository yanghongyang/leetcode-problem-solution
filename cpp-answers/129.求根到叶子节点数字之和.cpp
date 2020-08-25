/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int dfs(TreeNode *root, int i)
    {
        if (root == NULL)
            return 0; //节点为空直接返回0
        int res = i * 10 + root->val;
        if (root->left == NULL && root->right == NULL) //如果节点为叶子节点
        {
            return res;
        }
        return dfs(root->left, res) + dfs(root->right, res);
    }
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};
// @lc code=end
