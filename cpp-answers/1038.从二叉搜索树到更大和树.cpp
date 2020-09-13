/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-13 08:02:33
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-13 08:04:43
 */
/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    void traverse(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            root->val = sum + root->val;
            sum = root->val;
            return;
        }
        traverse(root->right, sum);
        root->val = sum + root->val;
        sum = root->val;
        traverse(root->left, sum);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        traverse(root, sum);
        return root;
    }
};
// @lc code=end
