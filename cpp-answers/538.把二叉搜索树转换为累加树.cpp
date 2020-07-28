/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-08 10:17:30
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-08 10:21:53
 */
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void GT(TreeNode *root, int &preVal)
    {
        if (!root)
            return;
        //前往右孩子（肯定是大于root的）
        GT(root->right, preVal);
        //将preVal加入当前节点
        root->val += preVal;
        //将当前的节点值设置为新的prevVal
        preVal = root->val;
        //因为右子树的值肯定都比左子树大，所以从右到左相加才能保证左子树的正确性
        GT(root->left, preVal);
        return;
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int startVal = 0;
        GT(root, startVal);
        return root;
    }
};
// @lc code=end
