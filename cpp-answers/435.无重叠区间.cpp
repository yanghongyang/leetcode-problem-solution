/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-15 19:25:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-15 19:31:00
 */
/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = -1;
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> prev = intervals[0];

        for (vector<int> i : intervals)
        {
            if (prev[1] > i[0])
                ans++;
            else
                prev = i;
        }
        return ans;
    }
};
// @lc code=end
