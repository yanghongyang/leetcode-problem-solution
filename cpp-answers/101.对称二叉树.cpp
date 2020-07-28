/*
 * @Author: your name
 * @Date: 2020-05-31 00:22:08
 * @LastEditTime: 2020-05-31 00:40:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\101.对称二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return checkSymmetric(root->left, root->right);
    }

    bool checkSymmetric(TreeNode *leftSymmetricNode, TreeNode *rightSymmetricNode)
    {
        if (leftSymmetricNode == NULL && rightSymmetricNode == NULL)
            return true;
        if (leftSymmetricNode == NULL || rightSymmetricNode == NULL)
            return false;
        if (leftSymmetricNode->val == rightSymmetricNode->val)
        {
            return checkSymmetric(leftSymmetricNode->left, rightSymmetricNode->right) && (checkSymmetric(leftSymmetricNode->right, rightSymmetricNode->left));
        }
        return false;
    }
};
// @lc code=end
