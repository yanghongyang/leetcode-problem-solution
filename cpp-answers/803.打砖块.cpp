/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
/* class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &m)
    {
        if (i < 0 || i >= m.size() || j < 0 || j >= m[0].size() || m[i][j] != 1)
            return 0;
        m[i][j] = 2;
        return dfs(i + 1, j, m) + dfs(i - 1, j, m) + dfs(i, j + 1, m) + dfs(i, j - 1, m) + 1; //统计与其相连的砖块的个数
    }
    bool isConnected(int x, int y, vector<vector<int>> &m)
    {
        if (x == 0) //要打的砖块位于顶部，肯定相连
            return true;
        for (auto d : direction)
        {
            int xt = x + d[0];
            int yt = y + d[1];
            if (xt >= 0 && xt < m.size() && yt >= 0 && yt < m[0].size() && m[xt][yt] == 2)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int n = hits.size();
        vector<int> res(n, 0);
        vector<vector<int>> m = grid;
        for (auto h : hits)
        {
            m[h[0]][h[1]]--; //移走所有hits位置的砖块
        }
        //然后把所有与top相连的标记为2
        for (int i = 0; i < grid[0].size(); i++)
        {
            dfs(0, i, m);
        }
        //然后再把已经击中的砖头加回去
        for (int i = n - 1; i >= 0; i--)
        {
            int x = hits[i][0], y = hits[i][1];
            m[x][y]++;
            //如果加回去为1，则原来m[x][y]这个地方有砖块
            //在有砖块的情况下，如果与顶部相连，则以(x,y)这个位置为起点做dfs，记录与它相连的砖块个数
            if (m[x][y] == 1 && isConnected(x, y, m))
            {
                res[i] = dfs(x, y, m) - 1;
            }
        }
        return res;
    }

private:
    int TOP = 2;
    int BRICK = 1;
    int EMPTY = 0;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
}; */
class UnionFind
{
private:
    vector<int> parent, sz; //parent为节点的父节点，sz为整个连通域的大小
public:
    UnionFind(int n) : parent(n), sz(n)
    {
        //初始情况下每个节点的parent都是它本身，并且对应的连通域的大小都为1
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) //路径压缩找父亲
    {
        if (parent[x] == x)
            return x;
        else
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy) //如果不是一个父节点，则合并，并且更新父节点所在的连通域的大小
        {
            parent[fx] = fy;
            sz[fy] += sz[fx];
        }
        else
            return;
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};
class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int h = grid.size(), w = grid[0].size(); //h为二维网格的高，w为二维网格的宽
        int n = hits.size();
        vector<int> res(n, 0);
        UnionFind uf(h * w + 1); //二维转一维，计算方法与计算二维数组中元素的物理位置类似
        //第一步：拷贝数组并且移除hit中的砖块
        vector<vector<int>> m = grid;
        for (auto h : hits)
        {
            m[h[0]][h[1]] = 0; //移走所有hits位置的砖块
        }
        //这样以后就只剩下悬停的砖块和顶部相连的砖块了
        //对这些剩下的砖块进行并查集操作，形成一个又一个连通域
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (m[i][j] == 1) //如果m[i][j]=1，则说明可能是悬停砖块或者与顶部相连的砖块
                {
                    if (i == 0) //如果是顶部的砖块
                    {
                        uf.merge(h * w, j);
                    }
                    if (i > 0 && m[i - 1][j] == 1)
                    { //如果和正上方砖块相连
                        uf.merge(i * w + j, (i - 1) * w + j);
                    }
                    if (j > 0 && m[i][j - 1] == 1)
                    { //如果和正左边砖块相连
                        uf.merge(i * w + j, i * w + j - 1);
                    }
                }
            }
        }
        //然后再把已经击中的砖头加回去
        for (int i = n - 1; i >= 0; i--)
        {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0) //如果原先就没有砖块
                continue;
            int prev = uf.size(h * w); //原先顶部砖块形成的连通域的大小
            if (x == 0)
            {
                uf.merge(y, h * w); //如果击碎的砖块是顶部，则加上之后就与原先的顶部砖块形成的连通域合并
            }
            for (int i = 0; i < 4; i++)
            {
                int xt = direction[i][0] + x;
                int yt = direction[i][1] + y;
                if (xt >= 0 && xt < h && yt >= 0 && yt < w)
                {
                    if (m[xt][yt] == 1) //如果存在砖块
                    {
                        uf.merge(x * w + y, xt * w + yt); //更新连通域
                    }
                }
            }
            int sz = uf.size(h * w); //此时顶部连通域的大小
            res[i] = max(0, sz - prev - 1);
            m[x][y] = 1; //倒序还原砖块
        }
        return res;
    }

private:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
// @lc code=end
