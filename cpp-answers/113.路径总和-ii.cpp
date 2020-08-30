/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-30 17:43:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-30 17:46:14
 */
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void dfs(TreeNode *root, int sum, vector<int> &tmp, vector<vector<int>> &res)
    {
        if (!root)
            return;
        tmp.push_back(root->val);
        if ((!root->left) && (!root->right) && sum == root->val)
            res.push_back(tmp);
        dfs(root->left, sum - root->val, tmp, res);
        dfs(root->right, sum - root->val, tmp, res);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root, sum, tmp, res);
        return res;
    }
};
// @lc code=end
