/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 17:10:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 17:23:18
 */ 
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    //递归DFS
    /*
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if(!root)
            return 0;
        int s = !root -> left && !root -> right && isLeft ? root -> val : 0;
        return s + sumOfLeftLeaves(root -> left, true) + sumOfLeftLeaves(root -> right, false);
    }*/
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(!root)
            return 0;
        int s = 0;
        stack<pair<TreeNode*, bool>> st;
        st.emplace(root, false);
        while(!st.empty())
        {
            //C++11中大部分的容器对于添加元素除了传统的insert
            //或者pusb_back/push_front之外都提供一个新的函数叫做emplace。 
            pair<TreeNode*, bool> cur = st.top();
            st.pop();
            s += !cur.first -> left && !cur.first -> right && cur.second ? cur.first -> val : 0;
            if(cur.first -> left)
                st.emplace(cur.first -> left, true);
            if(cur.first -> right)
                st.emplace(cur.first -> right, false);
        }
        return s;
    }
};
// @lc code=end

