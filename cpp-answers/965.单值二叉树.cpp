/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 16:21:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 16:25:44
 */
/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool isUnivalTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left)
            {
                if (tmp->left->val != tmp->val)
                    return false;
                q.push(tmp->left);
            }
            if (tmp->right)
            {
                if (tmp->right->val != tmp->val)
                    return false;
                q.push(tmp->right);
            }
        }
        return true;
    }
};
// @lc code=end
