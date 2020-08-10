/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
class Solution {
public:
/*递归做法
    void inorder(TreeNode *root, vector<int> &nodes)
    {
        if(!root)
            return ;
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
*/
    //迭代方法，使用栈
 /*    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode *> todo;
        while(root || !todo.empty())
        {
            while(root)
            {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    } */
    //Morris遍历
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> nodes;
        while(root)
        {
            if(root -> left)
            {
                TreeNode* pre = root -> left;
                while(pre -> right && pre -> right != root)
                {
                    pre = pre -> right;
                }
                if(!pre -> right)
                {
                    pre -> right = root;
                    root = root -> left;
                }
                else 
                {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            }
            else 
            {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};
// @lc code=end

