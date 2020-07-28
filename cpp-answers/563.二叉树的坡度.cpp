/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-17 19:22:57
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 20:32:20
 */
/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int tiltnumber;
    int tilt(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        int lt = tilt(root->left);
        int rt = tilt(root->right);
        tiltnumber += abs(lt - rt);
        return lt + rt + root->val;
    }
    int findTilt(TreeNode *root)
    {
        int t = tilt(root);
        return tiltnumber;
    }
};
// @lc code=end
