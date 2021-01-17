/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class Solution
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
};
// @lc code=end
