/*
 * @Author: your name
 * @Date: 2020-05-28 21:27:10
 * @LastEditTime: 2020-05-28 21:31:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\9.回文数.cpp
 */
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        long sum = 0;
        long tmp = x;
        while (x > 0)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (tmp == sum);
    }
};
// @lc code=end
