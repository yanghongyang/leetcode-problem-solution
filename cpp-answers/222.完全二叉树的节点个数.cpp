/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-09 07:09:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-09 07:30:27
 */
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    //朴素递归法
    /*     int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->right) + countNodes(root->left);
    } */
    //同样朴素的递归法，进行了部分优化
    //根据完全二叉树的性质简化了遍历次数
    //参考自：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/c-san-chong-fang-fa-jie-jue-wan-quan-er-cha-shu-de/
    //统计树的深度
    /*     int countLevels(TreeNode *root)
    {
        int levels = 0;
        while (root)
        {
            root = root->left;
            levels++;
        }
        return levels;
    }
    int countNodes(TreeNode *root)
    {
        //利用完全二叉树性质简化遍历次数
        if (!root)
            return 0;
        int left_levels = countLevels(root->left);
        int right_levels = countLevels(root->right);
        //左子树深度等于右子树深度，则左子树是满二叉树
        if (left_levels == right_levels)
        {
            return countNodes(root->right) + (1 << left_levels);
        }
        else
        {
            return countNodes(root->left) + (1 << right_levels);
        }
    } */
    //二分搜索
    //这种方法利用了二叉树的性质
    //可以认为，完全二叉树中，除了最后一层，其他每层节点都是满的，并且最后一层的节点全部靠向左边
    int getDepth(TreeNode *root)
    {
        int depth = 0;
        while (root)
        {
            root = root->left;
            depth++;
        }
        return depth;
    }
    int countNodes(TreeNode *root)
    {
        TreeNode *cur = root;
        int level = 1;
        int h = getDepth(root);
        int numbers = 0;
        while (cur)
        {
            TreeNode *tmp = cur->right;
            if (level + getDepth(tmp) == h && tmp)
            {
                cur = cur->right;
                numbers += pow(2, h - level - 1);
                level += 1;
            }
            else
            {
                cur = cur->left;
                level += 1;
            }
        }
        return numbers + pow(2, h - 1);
    }
};
// @lc code=end
