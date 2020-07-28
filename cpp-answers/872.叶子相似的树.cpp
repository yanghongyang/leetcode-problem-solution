/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 11:55:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 11:58:26
 */
/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void dfs(TreeNode *root, vector<int> &tmp)
    {
        if (!root)
            return;
        if (!(root->left) && !(root->right))
        {
            tmp.push_back(root->val);
        }
        dfs(root->left, tmp);
        dfs(root->right, tmp);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> t1{};
        vector<int> t2{};
        dfs(root1, t1);
        dfs(root2, t2);

        return t1 == t2;
    }
};
// @lc code=end
