/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-24 20:22:58
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 20:31:19
 */
/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int res = 0;
        int n = timeSeries.size();
        if (n <= 0 || duration == 0)
            return 0;
        if (n == 1)
            return duration;
        for (int i = 0; i < n - 1; i++)
        {
            if (timeSeries[i] + duration <= timeSeries[i + 1])
            {
                res += duration;
            }
            else
            {
                res += (timeSeries[i + 1] - timeSeries[i]);
            }
        }
        res += duration;
        return res;
    }
};
// @lc code=end
