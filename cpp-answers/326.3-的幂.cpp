/*
 * @Author: your name
 * @Date: 2020-06-13 22:18:32
 * @LastEditTime: 2020-06-13 22:24:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\326.3-的幂.cpp
 */
/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};
// @lc code=end
