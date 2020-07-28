/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 14:38:59
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 14:41:10
 */
/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root && root->val != val)
        {
            root = root->val < val ? root->right : root->left;
        }
        return root;
    }
};
// @lc code=end
