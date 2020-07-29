/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-28 17:42:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-29 16:39:08
 */
/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    // root->val = min(root->left->val, root->right->val);
    // BFS + 队列 + 迭代
    // 特点： 根节点一定是最小的，但是根节点的孩子节点不一定是第二小的
    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root)
            return -1;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> tmp;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        sort(tmp.begin(), tmp.end());
        for (auto x : tmp)
            if (x != root->val)
                return x;
        return -1;
    }
};
// @lc code=end
