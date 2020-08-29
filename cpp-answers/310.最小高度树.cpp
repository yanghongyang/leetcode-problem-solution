/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-29 17:24:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-29 17:37:46
 */
/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1 && edges.size() == 0)
            return {0};
        vector<int> res;
        vector<int> indegree(n);
        vector<vector<int>> graph(n, vector<int>());
        queue<int> q;

        //构造邻接表
        for (auto item : edges)
        {
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }
        //构造入度表
        for (auto item : edges)
        {
            indegree[item[0]]++;
            indegree[item[1]]++;
        }
        //将叶子节点，也就是入度为1的点加入队列
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                q.push(i);
        }
        while (n > 2)
        {
            int count = q.size();
            n -= count;
            //每次将所有的叶子节点去除，并且将新的叶子节点加入队列
            while (count--)
            {
                int item = q.front();
                q.pop();
                int size = graph[item].size();
                for (int i = 0; i < size; i++)
                {
                    --indegree[item];
                    --indegree[graph[item][i]];
                    if (indegree[graph[item][i]] == 1)
                        q.push(graph[item][i]);
                }
            }
        }
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end
