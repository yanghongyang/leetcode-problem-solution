/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-09 07:53:24
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-09 07:57:27
 */
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    bool dfs(TreeNode *root, TreeNode *&ans, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return false;
        bool lson = dfs(root->left, ans, p, q);
        bool rson = dfs(root->right, ans, p, q);
        if ((lson && rson) || (root->val == p->val || root->val == q->val) && (lson || rson))
        {
            ans = root;
        }
        return lson || rson || (root->val == p->val) || (root->val == q->val);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans;
        dfs(root, ans, p, q);
        return ans;
    }
};
// @lc code=end
