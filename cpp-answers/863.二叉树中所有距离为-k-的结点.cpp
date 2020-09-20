/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    unordered_map<TreeNode *, TreeNode *> parent; //建立父子节点的映射
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        dfs(root, NULL); //记录父节点
        //以上操作完成了父子节点之间双向关系的建立
        //接下来需要使用BFS实现三个方向的搜索
        queue<TreeNode *> q;               //BFS套路
        unordered_set<TreeNode *> visited; //用set保存当前已经访问过的节点
        q.push(target);
        visited.insert(target);
        while (!q.empty())
        {
            if (K == 0) //这里已经延伸了K次，所以队中全部的结点就是所求节点
            {
                vector<int> ret;
                while (!q.empty())
                {
                    ret.push_back(q.front()->val);
                    q.pop();
                }
                return ret;
            }
            else //如果没伸展K次，那么需要在BFS队列中加入所有接下来一步的结点
            {
                int n = q.size(); //当前队列
                for (int i = 0; i < n; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left && visited.find(node->left) == visited.end())
                    {
                        q.push(node->left);
                        visited.insert(node->left);
                    }
                    if (node->right && visited.find(node->right) == visited.end())
                    {
                        q.push(node->right);
                        visited.insert(node->right);
                    }
                    if (parent[node] != NULL && visited.find(parent[node]) == visited.end())
                    {
                        q.push(parent[node]);
                        visited.insert(parent[node]);
                    }
                }
            }
            K--;
        }
        return vector<int>();
    }
    void dfs(TreeNode *root, TreeNode *pre)
    {
        if (root)
        {
            parent.insert({root, pre});
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }
};
// @lc code=end
