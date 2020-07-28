/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-17 18:44:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-17 18:51:31
 */
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
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
    void setDepth(Node *root, int &maxDepth, int level)
    {
        if (!root)
            return;
        maxDepth = max(maxDepth, level);
        for (int i = 0; i < root->children.size(); i++)
        {
            if (root->children[i])
            {
                setDepth(root->children[i], maxDepth, level + 1);
            }
        }
        return;
    }
    int maxDepth(Node *root)
    {
        int maxDepth = 0;
        setDepth(root, maxDepth, 1);
        return maxDepth;
    }
};
// @lc code=end
