/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-08 23:04:57
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-08 23:20:02
 */
/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
    vector<TreeNode *> allPossibleFBT(int N)
    {
        if (N % 2 == 0)
            return {};
        if (N == 1)
            return {new TreeNode(0)};
        vector<TreeNode *> ans;
        for (int lef = 1; lef + 1 < N; lef++)
        {
            vector<TreeNode *> left = allPossibleFBT(lef);
            vector<TreeNode *> right = allPossibleFBT(N - 1 - lef);
            for (TreeNode *l : left)
            {
                for (TreeNode *r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
