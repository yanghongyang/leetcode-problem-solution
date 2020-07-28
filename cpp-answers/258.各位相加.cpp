/*
 * @Author: your name
 * @Date: 2020-06-08 09:21:03
 * @LastEditTime: 2020-06-08 09:23:03
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\258.各位相加.cpp
 */
/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num % 9 == 0 && num != 0)
            return 9;
        return (num % 9);
    }
};
// @lc code=end
