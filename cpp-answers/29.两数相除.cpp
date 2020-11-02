/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-02 16:57:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-02 17:21:40
 */
/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
public:
    /* 朴素法：递归相减
    int div(long a, long b)
    {
        if (a < b)
            return 0;
        long count = 1;
        long tb = b; //在后面的代码中不更新b
        while ((tb + tb) <= a)
        {
            count = count + count; //最小解翻倍
            tb = tb + tb;
        }
        return count + div(a - tb, b); //递归
    }
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
                return -dividend;
            else
                return INT_MAX;
        }

        long a = dividend;
        long b = divisor;
        int sign = 1;

        if (a > 0 && b < 0 || (a < 0 && b > 0))
            sign = -1;

        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;

        long res = div(a, b);
        if (sign > 0)
            return res > INT_MAX ? INT_MAX : res;
        return -res;
    } */

    //数学法
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 0)
            return INT_MAX;

        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));

        if ((dividend < 0) ^ (divisor < 0))
            res = -res;
        if (res > INT_MAX)
            res = INT_MAX;

        return res;
    }
};
// @lc code=end
