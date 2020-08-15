/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-15 10:24:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-15 10:28:05
 */
/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int sum = 0;
    int sumEvenGrandparent(TreeNode *root)
    {
        if (!root)
            return 0;
        if (root->val % 2 == 0)
        {
            if (root->left)
            {
                if (root->left->left)
                    sum += root->left->left->val;
                if (root->left->right)
                    sum += root->left->right->val;
            }
            if (root->right)
            {
                if (root->right->left)
                    sum += root->right->left->val;
                if (root->right->right)
                    sum += root->right->right->val;
            }
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};
// @lc code=end
