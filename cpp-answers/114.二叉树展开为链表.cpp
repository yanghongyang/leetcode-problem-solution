/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-30 17:59:27
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-30 18:01:50
 */
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        if (root->left)
        {
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            while (root->right)
                root = root->right;
            root->right = right;
        }
    }
};
// @lc code=end
