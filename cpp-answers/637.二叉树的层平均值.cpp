/*
 * @Author: your name
 * @Date: 2020-06-13 20:08:46
 * @LastEditTime: 2020-06-13 20:12:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\637.二叉树的层平均值.cpp
 */
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};
        vector<double> avgs;
        queue<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int n = todo.size();
            double sum = 0.0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = todo.front();
                todo.pop();
                sum += node->val;
                if (node->left)
                    todo.push(node->left);
                if (node->right)
                    todo.push(node->right);
            }
            avgs.push_back(sum / n);
        }
        return avgs;
    }
};
// @lc code=end
