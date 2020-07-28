/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-09 23:06:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-09 23:11:15
 */
/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (!root)
            return root; //树为空节点，返回为空
        if (root->left)
            root->left = trimBST(root->left, L, R);
        if (root->right)
            root->right = trimBST(root->right, L, R);
        if (root->val < L || root->val > R)
        {
            if (root->left)
                root = root->left;
            else if (root->right)
                root = root->right;
            else if (!root->right && !root->left)
            {
                root = nullptr;
            }
        }
        return root;
    }
};
// @lc code=end
