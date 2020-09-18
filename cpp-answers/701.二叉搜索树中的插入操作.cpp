/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *node = new TreeNode(val);
        if (root == NULL)
            return node;
        TreeNode *z = root;
        TreeNode *y;
        while (root)
        {
            y = root;
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        if (val < y->val)
            y->left = node;
        else
            y->right = node;
        return z;
    }
};
// @lc code=end
