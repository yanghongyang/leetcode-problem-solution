/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-01 18:02:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-01 18:08:43
 */
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    //和层次遍历很像。
    //迭代法
    /*
    Node *connect(Node *root)
    {
        Node *pre = root, *cur;
        while (pre)
        {
            cur = pre;
            while (cur && cur->left)
            {
                cur->left->next = cur->right;
                if (cur->next)
                {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }*/
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        if (root->left)
        {
            root->left->next = root->right;
            if (root->next)
            {
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
// @lc code=end
