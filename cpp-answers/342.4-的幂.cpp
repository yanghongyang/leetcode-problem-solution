/*
 * @Author: your name
 * @Date: 2020-06-13 22:24:57
 * @LastEditTime: 2020-06-13 22:28:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\342.4-的幂.cpp
 */
/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        /*
        return fmod(log10(num) / log10(4), 1) == 0;
        */
        if (num <= 0)
            return false;
        //先判断是否是 2 的幂
        if ((num & num - 1) != 0)
            return false;
        //如果与运算之后是本身则是 4 的幂
        if ((num & 0x55555555) == num)
            return true;
        return false;
    }
};
// @lc code=end
