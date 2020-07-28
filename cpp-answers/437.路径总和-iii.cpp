/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 15:28:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 15:32:29
 */
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathcount;
    void getsum(TreeNode *root, int sum)
    {
        if (!root)
            return;
        if (root->val == sum)
            pathcount++;
        getsum(root->left, sum - root->val);
        getsum(root->right, sum - root->val);
    }
    int pathSum(TreeNode *root, int sum)
    {
        if (root)
        {
            getsum(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return pathcount;
    }
};
// @lc code=end
