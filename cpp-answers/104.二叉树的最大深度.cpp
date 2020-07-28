/*
 * @Author: your name
 * @Date: 2020-05-31 00:41:52
 * @LastEditTime: 2020-05-31 00:42:42
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\104.二叉树的最大深度.cpp
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// @lc code=end
