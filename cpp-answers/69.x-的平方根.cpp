/*
 * @Author: your name
 * @Date: 2020-05-30 01:17:18
 * @LastEditTime: 2020-05-30 01:26:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\69.x-的平方根.cpp
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long r = x;
        while (r * r > x)
        {
            r = (r + x / r) / 2;
        }
        return r;
    }
};
// @lc code=end
