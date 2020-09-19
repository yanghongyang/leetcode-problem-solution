/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        int level = 1;
        if (d == 1)
        {
            TreeNode *tmp = root;
            root = new TreeNode(v);
            root->left = tmp;
            root->right = nullptr;
        }
        else
        {
            helper(root, v, d, level);
        }
        return root;
    }
    void helper(TreeNode *root, int v, int d, int level)
    {
        if (!root)
            return;
        if (level == d - 1)
        {
            TreeNode *ltmp = root->left;
            TreeNode *rtmp = root->right;
            root->left = new TreeNode(v);
            root->right = new TreeNode(v);
            root->left->left = ltmp;
            root->right->right = rtmp;
        }
        helper(root->left, v, d, level + 1);
        helper(root->right, v, d, level + 1);
    }
};
// @lc code=end
