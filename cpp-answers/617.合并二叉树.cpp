/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 11:55:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 11:57:16
 */
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        t1->val += t2->val;
        if (t2->left)
            t1->left = mergeTrees(t1->left, t2->left);
        if (t2->right)
            t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
// @lc code=end
