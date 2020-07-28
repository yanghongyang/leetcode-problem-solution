/*
 * @Author: your name
 * @Date: 2020-06-09 08:31:54
 * @LastEditTime: 2020-06-09 08:39:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\226.翻转二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    /*
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);
        }
        return root;
    }
*/
    TreeNode *invertTree(TreeNode *root)
    {
        std::stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *p = stk.top();
            stk.pop();
            if (p)
            {
                stk.push(p->left);
                stk.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }
};
// @lc code=end
