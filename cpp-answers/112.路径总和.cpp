/*
 * @Author: your name
 * @Date: 2020-06-03 13:42:41
 * @LastEditTime: 2020-07-07 17:14:46
 * @LastEditors: Hongyang_Yang
 * @Description: In User Settings Edit
 * @FilePath: \postwoman-mastere:\leetcode刷题\112.路径总和.cpp
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
/*递归/深度优先
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        int newsum = sum - root->val;
        if (root->left == NULL && root->right == NULL)
        {
            return newsum == 0;
        }
        return hasPathSum(root->left, newsum) || hasPathSum(root->right, newsum);
    }
};*/
/*广度优先搜索*/
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        queue<TreeNode *> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while (!que_node.empty())
        {
            TreeNode *now = que_node.front();
            int temp = que_val.front();
            que_node.pop();
            que_val.pop();
            if (now->left == nullptr && now->right == nullptr)
            {
                if (temp == sum)
                    return true;
                continue;
            }
            if (now->left != nullptr)
            {
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }
            if (now->right != nullptr)
            {
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }
        return false;
    }
};
// @lc code=end
