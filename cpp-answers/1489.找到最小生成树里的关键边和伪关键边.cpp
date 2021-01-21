/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */

// @lc code=start
//并查集
class UnionFind
{
public:
    vector<int> parent;
    vector<int> sz;
    int n;
    //当前连通分量数目
    int setCount;

public:
    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), sz(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool uni(int x1, int y1)
    {
        int x = find(x1);
        int y = find(y1);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        sz[x] += sz[y];
        --setCount;
        return true;
    }
    bool isconnected(int x1, int y1)
    {
        int x = find(x1);
        int y = find(y1);
        return x == y;
    }
};
class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto &u, const auto &v) {
            return u[2] < v[2];
        });
        //计算value
        UnionFind uf(n);
        int value = 0;
        for (int i = 0; i < m; i++)
        {
            if (uf.uni(edges[i][0], edges[i][1]))
            {
                value += edges[i][2];
            }
        }
        vector<vector<int>> ans(2);
        for (int i = 0; i < m; i++)
        {
            //判断是否为关键边
            UnionFind uf1(n);
            int v = 0;
            for (int j = 0; j < m; j++)
            {
                if (i != j && uf1.uni(edges[j][0], edges[j][1]))
                {
                    v += edges[j][2];
                }
            }
            if (uf1.setCount != 1 || (uf1.setCount == 1 && v > value))
            {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            //判断是否为伪关键边
            uf1 = UnionFind(n);
            uf1.uni(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; j++)
            {
                if (i != j && uf1.uni(edges[j][0], edges[j][1]))
                {
                    v += edges[j][2];
                }
            }
            if (v == value)
            {
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};
// @lc code=end
