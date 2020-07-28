/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 22:09:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-12 10:31:46
 */
/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode *root, int k)
    {
        if ((!root) || (!root->left && !root->right))
            return false;
        else
            return search(root, k, root);
    }

    bool search(TreeNode *root, int k, TreeNode *curr)
    {
        int temp = k - root->val;
        if (traverse(curr, root, temp) == true)
            return true;
        if (root->left)
        {
            if (search(root->left, k, curr) == true)
                return true;
        }
        if (root->right)
        {
            if (search(root->right, k, curr) == true)
                return true;
        }
        return false;
    }
    bool traverse(TreeNode *root, TreeNode *curr, int n)
    {
        if (root->val == n && root != curr)
            return true;
        if (root->left)
        {
            if (traverse(root->left, curr, n) == true)
                return true;
        }
        if (root->right)
        {
            if (traverse(root->right, curr, n) == true)
                return true;
        }
        return false;
    }
};
// @lc code=end
