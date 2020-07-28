/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-17 21:18:33
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 21:24:04
 */ 
/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node *> s1, s2;
        vector<int> sol;
        if(!root)
            return sol;
        s1.push(root);
        while(!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);
            for(auto & child: root -> children)
            {
                s1.push(child);
            }
        }
        while(!s2.empty())
        {
            sol.push_back(s2.top() -> val);
            s2.pop();
        }
        return sol;
    }
};
// @lc code=end

