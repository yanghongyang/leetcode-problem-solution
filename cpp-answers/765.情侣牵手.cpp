/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
/* class Solution
{
public:
    int find(vector<int> &f, int x)
    {
        if (f[x] == x)
            return x;
        else
        {
            f[x] = find(f, f[x]);
        }
        return f[x];
    }
    void uni(vector<int> &f, int x, int y)
    {
        int fx = find(f, x);
        int fy = find(f, y);
        f[fx] = fy;
    }
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        int total = n / 2;
        vector<int> f(total, 0);
        for (int i = 0; i < total; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < n; i += 2) //把座位上的人看作节点，如果第i对和第j对坐在一起了，则在i号节点和j号节点之间连接一条边
        {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            uni(f, l, r);
        }
        unordered_map<int, int> m;
        for (int i = 0; i < total; i++) //统计每个连通分量包含的节点个数
        {
            int fx = find(f, i);
            m[fx]++;
        }
        int ret = 0;
        for (auto node : m)
        {
            ret += node.second - 1;
        }
        return ret;
    }
}; */
/* class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        int total = n / 2;
        vector<vector<int>> graph(total);
        for (int i = 0; i < n; i += 2)
        {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            if (l != r)
            {
                graph[l].push_back(r);
                graph[r].push_back(l);
            }
        }
        vector<int> visited(total, 0);
        int ret = 0;
        for (int i = 0; i < total; i++)
        {
            if (visited[i] == 0)
            {
                queue<int> q;
                visited[i] = 1;
                q.push(i);
                int cnt = 0;

                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    cnt += 1;

                    for (int y : graph[x])
                    {
                        if (visited[y] == 0)
                        {
                            visited[y] = 1;
                            q.push(y);
                        }
                    }
                }
                ret += cnt - 1;
            }
        }
        return ret;
    }
}; */
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto x : adj[node])
        {
            if (!visited[x])
                dfs(adj, x, visited);
        }
    }
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        int total = n / 2;
        vector<bool> visited(total, 0);
        int ans = 0;
        unordered_map<int, int> mp;
        vector<vector<int>> adj(n / 2);
        for (int i = 0; i < n; i++)
        {
            mp[row[i]] = i; //记录位置
        }
        for (int i = 0; i < n - 1; i += 2)
        {
            int tmp1 = mp[i];
            int tmp2 = mp[i + 1];
            if (tmp1 / 2 == tmp2 / 2)
                continue; //不用交换
            else
            {
                int node1 = tmp1 / 2;
                int node2 = tmp2 / 2;
                adj[node1].push_back(node2);
                adj[node2].push_back(node1);
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(adj, i, visited);
            }
        }
        return n / 2 - ans;
    }
};
// @lc code=end
