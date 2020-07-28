/*
 * @Author: your name
 * @Date: 2020-06-11 07:28:40
 * @LastEditTime: 2020-06-11 08:00:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\235.二叉搜索树的最近公共祖先.cpp
 */
/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

/*
从根节点开始遍历树
如果节点 ppp 和节点 qqq 都在右子树上，那么以右孩子为根节点继续 1 的操作
如果节点 ppp 和节点 qqq 都在左子树上，那么以左孩子为根节点继续 1 的操作
如果条件 2 和条件 3 都不成立，这就意味着我们已经找到节 ppp 和节点 qqq 的 LCA 了
*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        /*递归版本
        时间复杂度O(N)，空间复杂度O(N)
        if ((root->val > p->val) && (root->val > q->val))
            return lowestCommonAncestor(root->left, p, q);
        if ((root->val < p->val) && (root->val < q->val))
            return lowestCommonAncestor(root->right, p, q);

        return root;*/
        //非递归版本
        //时间复杂度O(N)，空间复杂度O(1)
        TreeNode *cur = root;
        while (true)
        {
            if (p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else if (p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else
                break;
        }
        return cur;
    }
};
// @lc code=end
