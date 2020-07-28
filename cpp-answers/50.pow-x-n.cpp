/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 16:48:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 17:01:23
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
/*
class Solution
{
public:
    //快速幂：迭代
    double myPow(double x, int n)
    {
        double res = 1.0;
        for (int i = n; i; i /= 2)
        {
            if (i & 1)
                res *= x;
            x *= x;
        }
        return n >= 0 ? res : 1 / res;
    }
};*/
class Solution
{
public:
    //快速幂：递归
    //时间复杂度：O(logn)，即递归的层数
    //空间复杂度：O(logn)，即递归的层数（递归的函数调用会使用栈空间
    double quickMul(double x, long long N)
    {
        if (N == 0)
            return 1.0;
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n)
    {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// @lc code=end
