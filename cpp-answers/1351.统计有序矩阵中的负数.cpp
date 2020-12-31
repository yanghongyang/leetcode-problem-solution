/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-31 22:22:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-31 22:57:59
 */
/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int row = m - 1, col = 0;
        int ans = 0;
        while (row >= 0 && col < n)
        {
            if (grid[row][col] < 0)
            {
                ans += n - col;
                row--;
            }
            else
            {
                ++col;
            }
        }
        return ans;
    }
};
// @lc code=end
