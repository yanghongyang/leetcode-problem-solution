/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-15 10:53:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-15 10:55:58
 */
/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }
    void pushAll(TreeNode *node)
    {
        for (; node != NULL;)
        {
            myStack.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
