/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-12 09:16:18
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-12 09:20:30
 */
/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        if (start == destination)
            return 0;
        if (start > destination)
            swap(start, destination);

        int n = distance.size();
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < start; i++)
        {
            sum1 += distance[i];
        }
        for (int i = start; i < destination; i++)
        {
            sum2 += distance[i];
        }
        for (int i = destination; i < n; i++)
        {
            sum1 += distance[i];
        }
        return min(sum1, sum2);
    }
};
// @lc code=end
