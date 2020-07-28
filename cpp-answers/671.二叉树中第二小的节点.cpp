/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-28 17:42:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-09 23:31:40
 */
/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode *root)
    {
        int res = INT_MAX;
        DFS(root, root->val, res);
        return res == INT_MAX ? -1 : res;
    }

    void DFS(TreeNode *root, int val, int &res)
    {
        if (!root)
            return;
        if (root->val != val)
            res = min(res, root->val);
        if (root->val == val)
            DFS(root->left, val, res), DFS(root->right, val, res);
    }
};
// @lc code=end
