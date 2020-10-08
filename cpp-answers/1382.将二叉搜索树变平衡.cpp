/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-09 06:54:27
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-09 06:59:58
 */
/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
    vector<TreeNode *> ans;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        ans.push_back(root);
        inorder(root->right);
    }
    TreeNode *build(int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        ans[mid]->left = build(l, mid - 1);
        ans[mid]->right = build(mid + 1, r);
        return ans[mid];
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        return build(0, ans.size());
    }
};
// @lc code=end
