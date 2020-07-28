/*
 * @Author: your name
 * @Date: 2020-06-05 22:25:16
 * @LastEditTime: 2020-06-05 22:30:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\172.阶乘后的零.cpp
 */
/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};
// @lc code=end
