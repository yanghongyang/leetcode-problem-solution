/*
 * @Author: your name
 * @Date: 2020-06-07 06:54:49
 * @LastEditTime: 2020-06-07 07:13:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\204.计数质数.cpp
 */
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        bool prime[n + 1];
        int res = 0;
        for (int i = 0; i <= n; i++)
            prime[i] = true;
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (prime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
                res++;
        }
        return res;
    }
};
// @lc code=end
