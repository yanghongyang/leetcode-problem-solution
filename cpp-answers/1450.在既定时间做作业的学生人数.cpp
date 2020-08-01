/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-01 18:38:22
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-01 18:39:09
 */
/*
 * @lc app=leetcode.cn id=1450 lang=cpp
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int cnt = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            if (endTime[i] >= queryTime && startTime[i] <= queryTime)
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end
