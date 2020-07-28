/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 21:42:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-19 21:50:55
 */
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode *root)
    {
        int m = INT_MAX;
        vector<int> A;
        traverse(root, A);

        sort(A.begin(), A.end());

        for (auto i = 0; i < A.size() - 1; i++)
        {
            m = min(m, A[i + 1] - A[i]);
        }

        return m;
    }
    void traverse(TreeNode *root, vector<int> &A)
    {
        if (!root)
            return;
        A.push_back(root->val);

        if (root->left)
            traverse(root->left, A);
        if (root->right)
            traverse(root->right, A);

        return;
    }
};
// @lc code=end
