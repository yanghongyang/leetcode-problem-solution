/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-02 21:17:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-02 21:36:16
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution
{
public:
    //DFS解法
    /*     void dfs(vector<vector<int>> &grid, int i, int j, int &area)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1)
        {
            area++;
            grid[i][j] = 0;
            dfs(grid, i, j + 1, area);
            dfs(grid, i, j - 1, area);
            dfs(grid, i - 1, j, area);
            dfs(grid, i + 1, j, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int tmp = 0;
                    dfs(grid, i, j, tmp);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    } */
    //BFS解法
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> direction;
        direction.push_back({0, 1});
        direction.push_back({0, -1});
        direction.push_back({1, 0});
        direction.push_back({-1, 0});
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    queue<pair<int, int>> q; //存储grid[i][j]==1时的横纵坐标
                    grid[i][j] = 0;
                    q.push({i, j});
                    int cnt = 1; //记录面积
                    while (!q.empty())
                    {
                        pair<int, int> tmp = q.front(); //取队首元素
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int row = tmp.first + direction[k].first;
                            int col = tmp.second + direction[k].second;
                            if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1)
                            {
                                cnt++;
                                grid[row][col] = 0;
                                q.push({row, col});
                            }
                        }
                    }
                    ans = max(cnt, ans);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
