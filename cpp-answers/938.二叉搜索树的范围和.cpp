/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 10:51:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 10:58:22
 */
/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        int ans = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *tmp = st.top();
            st.pop();
            if (tmp->val >= L && tmp->val <= R)
                ans += tmp->val;
            if (tmp->val > L)
            {
                if (tmp->left)
                {
                    st.push(tmp->left);
                }
            }
            if (tmp->val < R)
            {
                if (tmp->right)
                {
                    st.push(tmp->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
