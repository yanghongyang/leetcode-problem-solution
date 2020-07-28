/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 21:18:26
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 21:25:00
 */
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    //dfs
public:
    void subtreeComparator(TreeNode *s, TreeNode *t, bool &areidentical)
    {
        if ((!s && !t) || !areidentical)
            return;
        if (!s || !t || s->val != t->val)
        {
            areidentical = false;
            return;
        }
        if (s->val == t->val && areidentical)
        {
            subtreeComparator(s->left, t->left, areidentical);
            subtreeComparator(s->right, t->right, areidentical);
        }
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s->val == t->val)
        {
            bool areidentical = true;
            subtreeComparator(s, t, areidentical);
            if (areidentical)
                return true;
        }
        return (s->left && isSubtree(s->left, t)) || (s->right && isSubtree(s->right, t));
    }
};
// @lc code=end
