/*
 * @Author: your name
 * @Date: 2020-06-13 20:01:20
 * @LastEditTime: 2020-06-13 20:04:36
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\476.数字的补数.cpp
 */
/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        int tmp = 1;
        while (tmp < num)
        {
            tmp <<= 1;
            tmp += 1;
        }
        return (tmp ^ num);
    }
};
// @lc code=end
