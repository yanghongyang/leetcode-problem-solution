/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-15 09:12:57
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-15 09:29:37
 */
/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
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
    /*?:符号的应用(null coalescing operator)
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
            return nullptr;
        else if (original == target)
            return cloned;
        return getTargetCopy(original->left, cloned->left, target) ?: getTargetCopy(original->right, cloned->right, target);
    }
*/
    /*     void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target, TreeNode *&resultNode)
    {
        if (!original || resultNode)
            return;
        if (original == target)
            resultNode = cloned;
        if (original->left)
            dfs(original->left, cloned->left, target, resultNode);
        if (original->right)
            dfs(original->right, cloned->right, target, resultNode);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *resultNode(nullptr);
        dfs(original, cloned, target, resultNode);
        return resultNode;
    } */
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (!original)
            return nullptr;
        queue<TreeNode *> todo1, todo2;
        todo1.push(original);
        todo2.push(cloned);
        while (!todo1.empty())
        {
            if (todo1.front() == target)
                return todo2.front();
            if (todo1.front()->left)
            {
                todo1.push(todo1.front()->left);
                todo2.push(todo2.front()->left);
            }
            if (todo1.front()->right)
            {
                todo1.push(todo1.front()->right);
                todo2.push(todo2.front()->right);
            }
            todo1.pop();
            todo2.pop();
        }
        return nullptr;
    }
};
// @lc code=end
