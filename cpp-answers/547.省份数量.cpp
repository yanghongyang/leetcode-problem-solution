/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-07 08:14:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-07 09:12:30
 */
/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
/* class Solution
{
public:
    void dfs(vector<vector<int>> &M, vector<bool> &visited, int i)
    {
        visited[i] = 1;
        for (int j = 0; j < M.size(); j++)
        {
            if (i != j && M[i][j] && !visited[j])
            {
                dfs(M, visited, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int cnt = 0;
        int n = M.size();
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(M, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
}; */
/* class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        int cnt = 0;
        int n = M.size();
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int t = q.front();
                    q.pop();
                    visited[t] = 1;
                    for (int j = 0; j < n; j++)
                    {
                        if (t != j && M[t][j] && !visited[j])
                        {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
}; */
class Solution
{
public:
    int find(vector<int> &parent, int n)
    {
        return parent[n] == n ? n : find(parent, parent[n]);
    }
    void Union(vector<int> &parent, int m, int n)
    {
        int pm = find(parent, m);
        int pn = find(parent, n);
        if (pm != pn)
        {
            parent[pm] = pn;
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int cnt = 0;
        int n = M.size();
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] && i != j)
                {
                    Union(parent, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end
