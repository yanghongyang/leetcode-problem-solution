/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-09 07:37:12
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-09 07:51:15
 */
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    //一种可能的递归方法
    /* int find(TreeNode *root, int &k)
    {
        if (root)
        {
            int x = find(root->left, k);
            return !k ? x : !--k ? root->val : find(root->right, k);
        }
        return 0;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        return find(root, k);
    } */
    //个人更倾向于这种递归23333简单粗暴
    /*     void inorder(TreeNode *root, vector<int> &sorted)
    {
        if (!root)
            return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> tmp;
        inorder(root, tmp);
        return tmp[k - 1];
    } */
    //当然递归方法不是很友好，因此改成迭代
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> tmp;
        while (true)
        {
            while (root)
            {
                tmp.push(root);
                root = root->left;
            }
            root = tmp.top();
            tmp.pop();
            if (--k == 0)
                return root->val;
            root = root->right;
        }
        return 0;
    }
};
// @lc code=end
