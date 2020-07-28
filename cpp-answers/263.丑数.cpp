/*
 * @Author: your name
 * @Date: 2020-06-08 09:17:39
 * @LastEditTime: 2020-06-08 09:18:35
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\263.丑数.cpp
 */
/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int num)
    {
        for (int i = 2; i < 6 && num; i++)
        {
            while (num % i == 0)
                num /= i;
        }
        return num == 1;
    }
};
// @lc code=end
