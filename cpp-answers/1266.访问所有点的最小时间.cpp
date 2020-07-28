/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 17:13:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 17:16:13
 */
/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */

// @lc code=start
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int res = 0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            res += max(abs(points[i + 1][1] - points[i][1]), abs(points[i + 1][0] - points[i][0]));
        }
        return res;
    }
};
// @lc code=end
