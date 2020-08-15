/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-15 10:30:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-15 10:37:21
 */
/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    void dfs(TreeNode *root, int n, int &deepestSum, int &h)
    {
        if (!root)
            return;
        if (n == h)
            deepestSum += root->val;
        if (n > h)
        {
            deepestSum = root->val;
            h = n;
        }
        dfs(root->left, n + 1, deepestSum, h);
        dfs(root->right, n + 1, deepestSum, h);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int deepestSum = 0;
        int h = 1;
        dfs(root, 1, deepestSum, h);
        return deepestSum;
    }
};
// @lc code=end
