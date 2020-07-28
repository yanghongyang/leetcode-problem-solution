/*
 * @Author: your name
 * @Date: 2020-06-11 07:26:18
 * @LastEditTime: 2020-06-11 07:27:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\509.斐波那契数.cpp
 */
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        int f = 0, s = 1;
        int res = 0;
        for (int i = 2; i <= N; i++)
        {
            res = f + s;
            f = s;
            s = res;
        }
        return res;
    }
};
// @lc code=end
