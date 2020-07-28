/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 21:54:57
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-19 21:58:08
 */
/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int minDiffInBST(TreeNode *root)
    {
        int m = INT_MAX;
        vector<int> a;
        dfs(root, a);
        sort(a.begin(), a.end());

        for (auto i = 0; i < a.size() - 1; i++)
        {
            m = min(m, a[i + 1] - a[i]);
        }
        return m;
    }
    void dfs(TreeNode *root, vector<int> &a)
    {
        if (root == NULL)
            return;
        a.push_back(root->val);
        if (root->left)
            dfs(root->left, a);
        if (root->right)
            dfs(root->right, a);
        return;
    }
};
// @lc code=end
