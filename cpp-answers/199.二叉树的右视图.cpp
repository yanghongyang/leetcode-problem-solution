/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-28 17:08:20
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-28 17:18:14
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    //bfs
    /*     vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        while (!q.empty())
        {
            //只需将层次遍历每层最后一个节点压入res数组中即可
            res.push_back(q.back()->val);
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
        return res;
    } */
    //dfs
    vector<int> res;
    void dfs(TreeNode *root, int depth)
    {
        if (root == NULL)
            return;
        if (depth == res.size())
            res.push_back(root->val);
        depth++;
        dfs(root->right, depth);
        dfs(root->left, depth);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end
