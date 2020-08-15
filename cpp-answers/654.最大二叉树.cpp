/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-15 09:57:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-15 10:04:29
 */
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        auto it = max_element(nums.begin(), nums.end()); //找到最大元素
        int distance = std::distance(nums.begin(), it);  //找到其位置
        TreeNode *rootNode = new TreeNode(*it);
        if (nums.size() == 1)
            return rootNode;

        vector<int> leftTree{nums.begin(), nums.begin() + distance};

        vector<int> rightTree{nums.begin() + distance + 1, nums.end()};

        if (leftTree.size() == 0 && rightTree.size() == 0)
        {
            rootNode->left = nullptr;
            rootNode->right = nullptr;
            return rootNode;
        }
        else if (leftTree.size() > 0 && rightTree.size() == 0)
        {
            rootNode->right = nullptr;
            rootNode->left = constructMaximumBinaryTree(leftTree);
        }
        else if (leftTree.size() == 0 && rightTree.size() > 0)
        {
            rootNode->left = nullptr;
            rootNode->right = constructMaximumBinaryTree(rightTree);
        }
        else
        {
            rootNode->left = constructMaximumBinaryTree(leftTree);
            rootNode->right = constructMaximumBinaryTree(rightTree);
        }
        return rootNode;
    }
};
// @lc code=end
