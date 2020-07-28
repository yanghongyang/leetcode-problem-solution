/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 16:22:16
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-19 16:31:17
 */ 
/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();    //行
        int n = grid[0].size(); //列
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans += 4;
                    if(i + 1 < m && grid[i + 1][j] == 1)
                    {
                        ans --;
                    }
                    if(i - 1 >= 0 && grid[i - 1][j] == 1)
                    {
                        ans --;
                    }
                    if(j - 1 >= 0 && grid[i][j - 1] == 1)
                    {
                        ans --;
                    }
                    if(j + 1 < n && grid[i][j + 1] == 1)
                    {
                        ans --;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

