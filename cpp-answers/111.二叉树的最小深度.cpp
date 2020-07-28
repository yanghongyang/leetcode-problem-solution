/*
 * @Author: your name
 * @Date: 2020-05-31 23:43:59
 * @LastEditTime: 2020-06-03 13:39:42
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \postwoman-mastere:\leetcode刷题\111.二叉树的最小深度.cpp
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int L = minDepth(root->left);
        int R = minDepth(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }
};
// @lc code=end
