/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 19:01:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-29 16:55:39
 */
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
/*class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1') //找到为1的陆地，调用dfs使之成为大海
                {
                    res++; //记录调用的次数
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') //边界条件（“撞南墙”）
            return;
        grid[i][j] = '0'; //记录节点轨迹，将访问过的陆地变成水
        //递归调用，控制遍历方向，左右上下
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};*/
//思路2：并查集
/* class UnionFind
{
public:
    vector<int> parent;
    int cnt; //连通分量的个数
    UnionFind(int n, int cnt)
    {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        this->cnt = cnt;
    }
    int Find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y)
    {
        int px = Find(x), py = Find(y);
        if (px != py)
        {
            parent[px] = py;
            cnt--;
        }
    }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                { //记录当前为1的，因为可能是岛屿
                    cnt++;
                }
            }
        }
        UnionFind *uf = new UnionFind(m * n, cnt);
        int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + direc[d][0];
                        int nj = j + direc[d][1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == '0')
                        {
                            continue;
                        }
                        int id1 = get(i, j);
                        int id2 = get(ni, nj);
                        uf->Union(id1, id2);
                    }
                }
            }
        }
        return uf->cnt;
    }

private:
    int m, n;
    int get(int i, int j)
    {
        return i * n + j;
    }
}; */
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        if (!nr)
            return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == '1')
                {
                    num_islands++;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty())
                    {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row + 1][col] == '1')
                        {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                        {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col + 1] == '1')
                        {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};
// @lc code=end
