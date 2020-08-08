/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
class Solution {
public:
    TreeNode* s1 = NULL, *s2 = NULL, *pre = NULL;
    void recoverTree(TreeNode* root) {
        TreeNode * cur = root;  //游标
        while(cur != NULL)
        {
            if(cur -> left != NULL) //进入左子树
            {
                //找到cur的前驱结点，分两种情况
                //1. cur的左子结点没有右子结点，那么cur的左子结点就是前驱
                //2. cur的左子结点有右子结点，就一路右下，走到底就是cur的前驱
                TreeNode * predecessor = cur -> left;
                while(predecessor -> right != NULL && predecessor -> right != cur)
                {
                    predecessor = predecessor -> right;
                }
                //前驱还没有指向自己，说明左边还没有遍历，将前驱的右指针指向自己，后进入前驱
                if(predecessor -> right == NULL)
                {
                    predecessor -> right = cur;
                    cur = cur -> left;
                }
                else 
                {
                    //前驱已经指向自己了，直接比较是否有逆序对，然后进入右子树
                    if(pre != NULL && cur -> val < pre -> val)
                    {
                        if(s1 == NULL)
                            s1 = pre;
                        s2 = cur;
                    }
                    pre = cur;
                    predecessor -> right = NULL;
                    cur = cur -> right;
                }
            }
            else 
            {
                //左子树为空时，检查是否有逆序对，然后进入右子树
                if(pre != NULL && cur -> val < pre -> val)
                {
                    if(s1 == NULL)
                        s1 = pre;
                    s2 = cur;
                }
                pre = cur;
                cur = cur -> right;
            }
        }
        //进行交换
        int t = s1 -> val;
        s1 -> val = s2 -> val;
        s2 -> val = t;
        return ;
    }
};
// @lc code=end

