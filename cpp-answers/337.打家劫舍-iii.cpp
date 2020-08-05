/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-05 14:53:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-05 15:51:20
 */
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    //暴力法，超时
    /*
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int money = root->val;
        if (root->left != NULL)
        {
            money += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right != NULL)
        {
            money += (rob(root->right->left) + rob(root->right->right));
        }
        return max(money, rob(root->left) + rob(root->right));
    }
    */
    //少量的优化：记忆化
    //性能大幅度提升！不超时了，并且内存消耗变少
    /*
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> memo;
        return robInternal(root, memo);
    }
    int robInternal(TreeNode *root, unordered_map<TreeNode *, int> &memo)
    {
        if (root == NULL)
            return 0;
        if (memo.find(root) != memo.end())
            return memo[root];
        int money = root->val;
        if (root->left != NULL)
        {
            money += (robInternal(root->left->left, memo) + robInternal(root->left->right, memo));
        }
        if (root->right != NULL)
        {
            money += (robInternal(root->right->left, memo) + robInternal(root->right->right, memo));
        }
        int result = max(money, robInternal(root->left, memo) + robInternal(root->right, memo));
        memo[root] = result;
        return result;
    }*/
    //树形dp
    //用两个hash map分别记录当前节点选中和未选中的最大值
    /*
    unordered_map<TreeNode *, int> yes, no;
    int rob(TreeNode *root)
    {
        robInterval(root);
        return max(yes[root], no[root]);
    }
    void robInterval(TreeNode *root)
    {
        if (root == NULL)
            return;
        robInterval(root->left);
        robInterval(root - > right);
        yes[root] = root->val + no[root->left] + no[root->right];
        no[root] = max(yes[root->left], no[root->left]) + max(yes[root->right], no[root->right]);
    }*/
    //对树状dp的朴素做法进行空间压缩，不使用两个hash map而是使用两个变量来记录遍历过程中出现的问题
    int rob(TreeNode *root)
    {
        int l = 0, r = 0;
        return robInterval(root, l, r);
    }
    int robInterval(TreeNode *root, int &l, int &r)
    {
        if (!root)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = robInterval(root->left, ll, lr);
        r = robInterval(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};
// @lc code=end
