/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-17 23:57:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-18 00:11:43
 */
/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode *root)
    {
        unsigned long long ans = 1;
        if (root)
        {
            queue<pair<TreeNode *, unsigned long long>> q;
            q.push({root, 0});
            while (!q.empty())
            {
                ans = max(ans, q.back().second - q.front().second + 1);
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    TreeNode *cur = q.front().first;
                    unsigned long long curInd = q.front().second;
                    q.pop();
                    if (cur->left)
                    {
                        q.push({cur->left, 2 * curInd});
                    }
                    if (cur->right)
                    {
                        q.push({cur->right, 2 * curInd + 1});
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
