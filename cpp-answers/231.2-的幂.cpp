/*
 * @Author: your name
 * @Date: 2020-06-09 08:40:24
 * @LastEditTime: 2020-06-09 08:40:54
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\231.2-的幂.cpp
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && !(n & (n - 1));
    }
};
// @lc code=end
