/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-08 05:30:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-08 05:34:09
 */
/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {

            for (int j = 0; j < grid[0].size(); j++)
            {
                int val = grid[i][j];
                if (val >= 2)
                {
                    result += 10 + 4 * (val - 2);
                }
                else
                    result += 6 * val;
                if (i - 1 >= 0 && grid[i - 1][j] > 0)
                    result -= 2 * min(val, grid[i - 1][j]);
                if (j - 1 >= 0 && grid[i][j - 1] > 0)
                {
                    result -= 2 * min(val, grid[i][j - 1]);
                }
            }
        }
        return result;
    }
};
// @lc code=end
