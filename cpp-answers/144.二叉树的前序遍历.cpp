/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-19 10:10:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-19 10:19:14
 */
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    /*
    void preorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    */
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        if (root == NULL)
            return res;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }
        return res;
    }
};
// @lc code=end
