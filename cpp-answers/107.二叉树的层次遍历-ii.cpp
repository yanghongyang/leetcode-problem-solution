/*
 * @Author: your name
 * @Date: 2020-05-31 00:43:30
 * @LastEditTime: 2020-05-31 00:46:39
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\107.二叉树的层次遍历-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level)
    {
        if (!node)
            return;
        if (level >= ans.size())
            ans.push_back({});
        ans[level].push_back(node->val);
        levelOrder(ans, node->left, level + 1);
        levelOrder(ans, node->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        levelOrder(ans, root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
