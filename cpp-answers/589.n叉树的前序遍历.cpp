/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-13 20:14:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 19:22:24
 */
/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    /*
    vector<int> preorder(Node *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        ret.push_back(root->val);
        for (auto &c : root->children)
        {
            vector<int> pre = preorder(c);
            ret.insert(ret.end(), pre.begin(), pre.end());
        }
        return ret;
    }*/

    vector<int> preorder(Node *root)
    {
        vector<int> ret;
        if (root == nullptr)
            return ret;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            for (auto it = cur->children.rbegin(); it != cur->children.rend(); it++) //crbegin是栈顶 crend是栈底 因为是栈，所以从后向前遍历
            {
                st.push(*it);
            }
        }
        return ret;
    }
};
// @lc code=end
