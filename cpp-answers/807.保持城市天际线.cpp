/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-29 19:25:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-29 19:28:08
 */
/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int res = 0;
        vector<int> row(grid.size(), 0);
        vector<int> col(grid.size(), 0);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] >= row[i])
                {
                    row[i] = grid[i][j];
                }
                if (grid[i][j] >= col[j])
                {
                    col[j] = grid[i][j];
                }
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                res += min(row[i], col[j]) - grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
