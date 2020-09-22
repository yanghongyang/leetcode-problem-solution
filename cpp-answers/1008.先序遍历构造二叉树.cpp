/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 先序遍历构造二叉树
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
    TreeNode *InsertBST(TreeNode *root, int i)
    {
        if (!root)
            return new TreeNode(i);
        if (i < root->val)
            root->left = InsertBST(root->left, i);
        else
            root->right = InsertBST(root->right, i);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = NULL;
        for (int i : preorder)
        {
            root = InsertBST(root, i);
        }
        return root;
    }
};
// @lc code=end
