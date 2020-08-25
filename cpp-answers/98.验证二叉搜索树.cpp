/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-25 07:48:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-25 08:05:24
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool check(TreeNode *root, long long lower, long long higher)
    {
        if (!root)
            return true;
        if (root->val <= lower || root->val >= higher)
            return false;
        return (check(root->left, lower, root->val) && (check(root->right, root->val, higher)));
    }
    bool isValidBST(TreeNode *root)
    {
        TreeNode *pre = NULL;
        return check(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
