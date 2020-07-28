/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-26 08:21:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-26 08:25:07
 */
/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode *root)
    {
        int maxlen = 0;
        DFS(root, maxlen);
        return maxlen;
    }

    int DFS(TreeNode *root, int &maxlen)
    {
        if (!root)
            return 0;
        int left = DFS(root->left, maxlen);
        int right = DFS(root->right, maxlen);
        if (!root->left || root->left->val != root->val)
            left = 0;
        if (!root->right || root->right->val != root->val)
            right = 0;
        maxlen = max(maxlen, left + right);
        return max(left, right) + 1;
    }
};
// @lc code=end
