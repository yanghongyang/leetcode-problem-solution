/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 16:33:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 17:55:02
 */
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    //中序遍历
    void recur(TreeNode *root, vector<int> &res, int &val, int &count, int &maxCount)
    {
        if (!root)
            return;
        recur(root->left, res, val, count, maxCount); //左孩子
        if (root->val == val)                         //根节点
            count++;
        else
        {
            if (count > maxCount)
            {
                res.clear();
                res.push_back(val);
                maxCount = count;
            }
            else if ((count != 0) && (count == maxCount))
            {
                res.push_back(val);
            }
            count = 1;
            val = root->val;
        }
        recur(root->right, res, val, count, maxCount); //右孩子
        return;
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        int val = INT_MIN, count = 0, maxCount = 0;
        recur(root, res, val, count, maxCount);
        if (count > maxCount)
        {
            res.clear();
            res.push_back(val);
        }
        else if ((count != 0) && (count == maxCount))
        {
            res.push_back(val);
        }
        return res;
    }
};
// @lc code=end
