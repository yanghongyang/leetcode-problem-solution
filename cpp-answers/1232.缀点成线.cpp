/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 17:03:56
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 17:07:35
 */
/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() <= 2)
            return true;
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); i++)
        {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if ((y - y1) * (x1 - x2) != (x - x1) * (y1 - y2))
                return false;
        }
        return true;
    }
};
// @lc code=end
