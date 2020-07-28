/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-20 20:40:12
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-21 09:01:43
 */
/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    int xDepth = -1;
    int yDepth = -1;
    bool isCousins(TreeNode *root, int x, int y)
    {
        solve(root, x, y, 0);
        return xDepth != -1 && xDepth == yDepth;
    }

    void solve(TreeNode *root, int x, int y, int depth)
    {
        if (!root)
            return;
        if (root->left && root->right && (root->left->val == x || root->left->val == y) && (root->right->val == x || root->right->val == y))
            return;
        if (root->val == x)
        {
            xDepth = depth;
            return;
        }
        if (root->val == y)
        {
            yDepth = depth;
            return;
        }

        solve(root->left, x, y, depth + 1);
        solve(root->right, x, y, depth + 1);
    }
};
// @lc code=end
