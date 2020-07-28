/*
 * @Author: your name
 * @Date: 2020-06-06 22:30:16
 * @LastEditTime: 2020-06-06 22:34:50
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\190.颠倒二进制位.cpp
 */
/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ret = 0, power = 31;
        while (n != 0)
        {
            ret += (n & 1) << power;
            n = n >> 1;
            power -= 1;
        }
        return ret;
    }
};
// @lc code=end
