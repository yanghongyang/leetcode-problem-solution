/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-18 00:52:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-18 00:58:40
 */
/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode *pruneSubTree(TreeNode *&root)
    {
        if (!root)
            return nullptr;
        root->left = pruneSubTree(root->left);
        root->right = pruneSubTree(root->right);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        return root;
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        pruneSubTree(root);
        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
            return nullptr;
        return root;
    }
};
// @lc code=end
