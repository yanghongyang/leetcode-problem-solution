/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-25 08:41:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-25 08:50:49
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
    {
        if (ps > pe)
            return nullptr;
        TreeNode *node = new TreeNode(postorder[pe]); //后序遍历的最后一个点是根节点
        int pos;
        for (int i = is; i <= ie; i++)
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
        node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
        return node;
    }
};
// @lc code=end
