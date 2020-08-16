/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-16 10:47:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-16 10:54:10
 */
/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    //最直观的dp
    /* int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++)
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }
        return sum[m - 1][n - 1];
    } */
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
        {
            cur[i] = cur[i - 1] + grid[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++)
            {
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
            }
        }
        return cur[m - 1];
    }
};
// @lc code=end
