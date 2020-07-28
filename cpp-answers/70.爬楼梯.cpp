/*
 * @Author: your name
 * @Date: 2020-05-30 01:27:21
 * @LastEditTime: 2020-05-30 01:27:59
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\70.爬楼梯.cpp
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int s1 = 1;
        int s2 = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret = s1 + s2;
            s2 = s1;
            s1 = ret;
        }
        return ret;
    }
};
// @lc code=end
