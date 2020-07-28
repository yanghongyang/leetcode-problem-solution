/*
 * @Author: your name
 * @Date: 2020-05-31 00:56:06
 * @LastEditTime: 2020-05-31 00:57:51
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\110.平衡二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = depth(root->left) + 1;
        int right = depth(root->right) + 1;

        if (abs(left - right) > 1 || left < 1 || right < 1)
        {
            return -1;
        }
        return (max(left, right));
    }
    bool isBalanced(TreeNode *root)
    {
        if (depth(root) < 0)
            return false;
        return true;
    }
};
// @lc code=end
