/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-16 10:12:17
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-16 10:21:44
 */
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *create(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie)
    {
        if (ps > pe)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[ps]); //先序遍历的第一个节点是根节点
        int pos;
        for (int i = is; i <= ie; i++) //在中序遍历中找到这个根节点的位置，则根节点左边的所有节点都是其左子树的节点，根节点右边所有的节点都是其右子树的节点
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);  //左子树
        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie); //右子树，提示pe - ie + pos + 1 = pe - (ie - pos - 1)
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end
