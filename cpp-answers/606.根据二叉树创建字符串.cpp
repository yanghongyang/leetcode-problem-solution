/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-01 19:50:09
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-11 16:37:31
 */
/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
/*法一：迭代法
class Solution
{
public:
    string tree2str(TreeNode *t)
    {
        if (!t)
            return "";
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        if (!t->left && !t->right)
            return to_string(t->val);
        if (!t->right)
            return to_string(t->val) + "(" + l + ")";
        return to_string(t->val) + "(" + l + ")" + "(" + r + ")";
    }
};
*/
/*
首先我们把根节点入栈。对于当前栈顶的元素，如果它没有遍历过，那么就把它加入到集合中，并开始对以它为根的子树进行前序遍历。
我们先在答案末尾添加一个 (，表示一个节点的开始，然后判断该节点的子节点个数。和方法一相同，
这里会出现四种情况：
1. 如果它没有子节点，我们什么都不做；
2. 如果它有两个子节点，那么我们先将右孩子入栈，再将左孩子入栈，这样就保证了前序遍历的顺序；
3. 如果它只有左孩子，那么我们将左孩子入栈；
4. 如果它只有右孩子，那么我们在答案末尾添加一个 () 表示空的左孩子，再将右孩子入栈。
注意这四种情况中，我们都不会将当前节点出栈，原因是我们一开始添加了 ( 表示节点的开始，在以当前节点为根的子树中所有节点遍历完成之后，我们才会在答案末尾添加 ) 表示节点的结束。
因此我们需要用上面提到的集合来存储遍历过的节点，如果当前栈顶的元素遍历过，那么我们就知道需要在答案末尾添加 )，并将这个节点出栈。
*/
class Solution
{
public:
    string tree2str(TreeNode *t)
    {
        if (t == nullptr)
            return "";
        string s;
        stack<TreeNode *> s1;
        stack<int> s2;
        int level = 0; //记录入栈的右节点的层数
        s1.push(t);
        while (true)
        {
            while (t)
            {
                s += "("; //对于根节点统一处理，返回时再去掉
                s += to_string(t->val);
                if (t->right)
                {
                    s1.push(t->right);
                    s2.push(level + 1);
                    if (!t->left)
                        s += "()";
                }
                t = t->left;
                level++;
            }
            if (s1.empty() || s2.empty())
                break;
            t = s1.top();
            s1.pop();
            //从当前层数到右栈层数所需要的")"
            for (int i = s2.top(); i < level; i++)
                s += ")";
            level = s2.top();
            s2.pop();
        }
        //从当前层数更新至底层(i=0)所需要的")"，由于最底层不需要")"，所以终止条件是level-1
        for (int i = 0; i < level - 1; i++)
            s += ")";
        return s.substr(1);
    }
};
// @lc code=end
