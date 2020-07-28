/*
 * @Author: your name
 * @Date: 2020-05-31 00:48:16
 * @LastEditTime: 2020-05-31 00:52:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\108.将有序数组转换为二叉搜索树.cpp
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *sortedArrayToBST1(vector<int> &nums, int start, int end)
    {
        if (end <= start)
            return NULL;
        int midIdx = (end + start) / 2;
        TreeNode *root = new TreeNode(nums[midIdx]);
        root->left = sortedArrayToBST1(nums, start, midIdx);
        root->right = sortedArrayToBST1(nums, midIdx + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST1(nums, 0, nums.size());
    }
};
// @lc code=end
