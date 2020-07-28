/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 11:04:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 11:22:31
 */
/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
/* class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *head = new TreeNode(0);
        TreeNode *pre = head;
        stack<TreeNode *> todo;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            pre->right = root;
            pre = pre->right;
            root->left = NULL;
            root = root->right;
        }
        return head->right;
    }
}; */
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
    void inOrder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> res;
        inOrder(root, res);
        TreeNode *ans = new TreeNode(0), *cur = ans;
        for (int v : res)
        {
            cur->right = new TreeNode(v);
            cur = cur->right;
        }

        return ans->right;
    }
};
// @lc code=end
