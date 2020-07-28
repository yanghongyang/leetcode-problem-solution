/*
 * @Author: your name
 * @Date: 2020-06-13 20:15:14
 * @LastEditTime: 2020-06-13 20:15:44
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\1009.十进制整数的反码.cpp
 */
/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int N)
    {
        int tmp = 1;
        while (tmp < N)
        {
            tmp <<= 1;
            tmp += 1;
        }
        return (tmp ^ N);
    }
};
// @lc code=end
